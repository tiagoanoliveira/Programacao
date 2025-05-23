#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include <vector>
#include <string>

namespace prog {
    namespace command {
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
