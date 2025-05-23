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


            for (size_t i = 0; i < scrim_filenames_.size(); ++i) {

                std::string file = scrim_filenames_[i];


                if (std::find(active_scrims_.begin(), active_scrims_.end(), file) != active_scrims_.end()) {

                    continue;

                }


                active_scrims_.push_back(file);

                ScrimParser parser;

                Scrim* inner_scrim = parser.parseScrim(file);


                if (!inner_scrim) {

                    active_scrims_.erase(std::remove(active_scrims_.begin(), active_scrims_.end(), file), active_scrims_.end());

                    continue;

                }


                {

                    std::vector<Command*> cmds = inner_scrim->getCommands();

                    for (size_t j = 0; j < cmds.size(); ++j) {

                        Command* cmd = cmds[j];

                        std::string name = cmd->name();

                        if (name == "Save" || name == "Open" || name == "Blank") continue;

                        current = cmd->apply(current);

                    }

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