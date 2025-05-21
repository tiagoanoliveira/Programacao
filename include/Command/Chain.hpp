#ifndef PROJECT_CHAIN_HPP
#define PROJECT_CHAIN_HPP

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

            static thread_local std::set<std::string> active_scrims_in_current_chain_;
            static thread_local int current_chain_depth_;
        };
    }
}

#endif //PROJECT_CHAIN_HPP