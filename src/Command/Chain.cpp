#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Scrim.hpp"
#include <sstream>
#include <vector>
#include <algorithm>

namespace prog {
    namespace command {

        std::vector<std::string> Chain::active_scrims_;

        Chain::Chain(const std::vector<std::string>& files) : Command("chain"), scrim_filenames_(files) {}

        Chain::~Chain() {}

        Image* Chain::apply(Image* img) {

            Image* current = img;
            // Iterate through all specified scrim files using index-based loop
            for (size_t i = 0; i < scrim_filenames_.size(); ++i) {
                std::string file = scrim_filenames_[i];

                // Check if this scrim is already being processed (recursion detection)
                // Uses std::find to search through the active_scrims_ vector
                if (std::find(active_scrims_.begin(), active_scrims_.end(), file) != active_scrims_.end()) {
                    continue; // Skip this file to avoid infinite recursion
                }

                // Mark this scrim as active (being processed)
                active_scrims_.push_back(file);

                // Create a parser to read the scrim file
                ScrimParser parser;
                Scrim* inner_scrim = parser.parseScrim(file);

                // Check if the file was loaded successfully
                if (!inner_scrim) {
                    // Remove from active list since it wasn't processed
                    // Uses erase-remove idiom to remove all occurrences of the file
                    active_scrims_.erase(std::remove(active_scrims_.begin(), active_scrims_.end(), file), active_scrims_.end());
                    continue; // Skip to next file
                }

                // Get all commands from the loaded scrim
                std::vector<Command*> cmds = inner_scrim->getCommands();

                // Process all commands in the scrim using index-based loop
                for (size_t j = 0; j < cmds.size(); ++j) {
                    Command* cmd = cmds[j];
                    std::string name = cmd->name();

                    // Skip specific commands that shouldn't be executed in a chain
                    // Save, Open, and Blank are file/state control commands
                    if (name == "Save" || name == "Open" || name == "Blank") continue;

                    // Apply the command to the current image
                    // The result becomes the new current image for the next command
                    current = cmd->apply(current);
                }
                delete inner_scrim;
                active_scrims_.erase(std::remove(active_scrims_.begin(), active_scrims_.end(), file), active_scrims_.end());
            }
            return current;
        }
        std::string Chain::toString() const {
            std::ostringstream ss;
            ss << name();
            for (size_t k = 0; k < scrim_filenames_.size(); ++k) {
                std::string f = scrim_filenames_[k];
                ss << " " << f;
            }
            return ss.str();
        }
    }
}