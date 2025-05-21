#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Scrim.hpp"
#include "Image.hpp"
#include "Logger.hpp"

#include "Command/Save.hpp"
#include "Command/Blank.hpp"
#include "Command/Open.hpp"

#include <sstream>
#include <filesystem>

namespace prog {
    namespace command {

        thread_local std::set<std::string> Chain::active_scrims_in_current_chain_;
        thread_local int Chain::current_chain_depth_ = 0;

        Chain::Chain(const std::vector<std::string>& files)
            : Command("chain"), scrim_filenames_(files) {}

        Chain::~Chain() {}

        Image* Chain::apply(Image* img) {
            Image* current_image = img;
            current_chain_depth_++;

            for (const auto& relative_scrim_path : scrim_filenames_) {
                std::string path_for_recursion_check;
                try {
                    std::filesystem::path fs_path(relative_scrim_path);
                    if (fs_path.is_relative() && !std::filesystem::current_path().empty()) {
                        path_for_recursion_check = std::filesystem::weakly_canonical(std::filesystem::current_path() / fs_path).string();
                    } else {
                        path_for_recursion_check = std::filesystem::weakly_canonical(fs_path).string();
                    }
                } catch (const std::filesystem::filesystem_error& e) {
                    
                    *Logger::out() << "Chain: Filesystem error normalizing path '" << relative_scrim_path << "': " << e.what()
                                   << ". Using original path for recursion check." << std::endl;
                    path_for_recursion_check = relative_scrim_path;
                }


                if (active_scrims_in_current_chain_.count(path_for_recursion_check)) {
                    *Logger::out() << "Recursive chain call detected for scrim '" << relative_scrim_path
                                    << "' (resolved as '" << path_for_recursion_check << "'). Skipping." << std::endl;
                    continue;
                }

                active_scrims_in_current_chain_.insert(path_for_recursion_check);
                *Logger::out() << "Chain: Executing scrim '" << relative_scrim_path << "'" << std::endl;

                ScrimParser inner_parser;
                Scrim* inner_scrim = inner_parser.parseScrim(relative_scrim_path);

                if (!inner_scrim) {
                    *Logger::err() << "Chain: Failed to parse inner scrim '" << relative_scrim_path << "'. Skipping." << std::endl;
                    active_scrims_in_current_chain_.erase(path_for_recursion_check);
                    continue;
                }

                const std::vector<Command*>& commands_to_run = inner_scrim->getCommands();
                for (Command* cmd : commands_to_run) {
                    // Ignorar apenas save, open e blank
                    if (dynamic_cast<command::Save*>(cmd) || dynamic_cast<command::Open*>(cmd) || dynamic_cast<command::Blank*>(cmd)) {
                        *Logger::out() << "Chain: Ignoring command '" << cmd->toString() << "' inside chained scrim '" << relative_scrim_path << "'." << std::endl;
                        continue;
                    }
                    
                    *Logger::out() << "Chain: Applying inner command '" << cmd->toString() << "' from '" << relative_scrim_path << "'." << std::endl;
                    current_image = cmd->apply(current_image);
                }
                
                delete inner_scrim;
                active_scrims_in_current_chain_.erase(path_for_recursion_check);
            }

            current_chain_depth_--;
            if (current_chain_depth_ == 0) {
                active_scrims_in_current_chain_.clear();
            }

            return current_image;
        }

        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << name();
            for (const auto& filename : scrim_filenames_) {
                ss << " " << filename;
            }
            return ss.str();
        }
    }
}
