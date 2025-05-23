#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Scrim.hpp"
#include "Logger.hpp"

#include "Command/Save.hpp"
#include <filesystem>

namespace prog {
    namespace command {

        std::set<std::string> Chain::active_scrims_;

        Chain::Chain(const std::vector<std::string>& files) : Command("chain"), scrim_filenames_(files) {}
        Chain::~Chain() {}

        Image* Chain::apply(Image* img) {
            Image* current = img;

            for (const auto& file : scrim_filenames_) {
                const auto abs_path = std::filesystem::absolute(file).string();

                if (active_scrims_.count(abs_path)) {
                    *Logger::out() << "Chain: Recursive inclusion of '" << file << "' detected, skipping.\n";
                    continue;
                }

                active_scrims_.insert(abs_path);
                ScrimParser parser;
                Scrim* inner_scrim = parser.parseScrim(file);

                if (!inner_scrim) {
                    *Logger::err() << "Chain: Could not load scrim file '" << file << "'\n";
                    active_scrims_.erase(abs_path);
                    continue;
                }

                for (auto* cmd : inner_scrim->getCommands()) {
                    auto name = cmd->name();
                    if (name == "Save" || name == "Open" || name == "Blank") {
                        // Ignorar sem log
                        continue;
                    }
                    current = cmd->apply(current);
                }

                delete inner_scrim;
                active_scrims_.erase(abs_path);
            }

            return current;
        }


        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << name();
            for (const auto& f : scrim_filenames_) ss << " " << f;
            return ss.str();
        }

    }
}