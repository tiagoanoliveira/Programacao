//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Command/Invert.hpp"
#include "Command/Grayscale.hpp"
#include "Command/Replace.hpp"
#include "Command/Fill.hpp"
#include "Command/HMirror.hpp"
#include "Command/VMirror.hpp"
#include "Command/Move.hpp"
#include "Command/Scale_up.hpp"
#include "Logger.hpp"
#include "Command/Resize.hpp"

#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        if (command_name == "invert") {
            return new command::Invert();
        }

        if (command_name == "to_gray_scale") {
            return new command::Grayscale();
        }

        if (command_name == "replace") {
            Color c1, c2;
            input >> c1 >> c2;
            return new command::Replace(c1, c2);
        }

        if (command_name == "fill") {
            int x, y, w, h;
            Color c;
            input >> x >> y >> w >> h >> c;
            return new command::Fill(x, y, w, h, c);
        }

        if (command_name == "h_mirror") {
            return new command::HMirror();
        }

        if (command_name == "v_mirror") {
            return new command::VMirror();
        }
        if (command_name == "resize") {
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new command::Resize(x, y, w, h);
        }
        if (command_name == "scaleup") {
            int x,y;
            input >> x >> y;
            return new command::Scale_up(x,y);
        }
        // TODO: implement cases for the new commands

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
