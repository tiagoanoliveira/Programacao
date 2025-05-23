#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include <vector>
#include <string>
#include <set>

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
            static std::set<std::string> active_scrims_;
        };
    }
}

#endif // CHAIN_HPP
