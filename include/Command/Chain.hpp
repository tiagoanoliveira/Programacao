#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include <vector>
#include <string>

namespace prog {
    namespace command {
        /**
         * @brief The Chain class implements a command to execute a sequence of commands from script files
         *
         * This class loads and executes a series of commands from multiple script files,
         * applying them sequentially to the image. It maintains a set of active scripts
         * to prevent infinite recursion when scripts reference each other.
         *
         * @param files Vector containing the filenames of script files to be executed in sequence
         */
        class Chain : public Command {
        public:
            Chain(const std::vector<std::string>& files);
            ~Chain() override;

            Image* apply(Image* img) override;
            std::string toString() const override;
        private:
            std::vector<std::string> scrim_filenames_;
            static std::vector<std::string> active_scrims_;
        };
    }
}

#endif // CHAIN_HPP
