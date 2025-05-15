#ifndef PROJECT_VMIRROR_HPP
#define PROJECT_VMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class VMirror : public Command {
        public:
            VMirror();

            ~VMirror();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_VMIRROR_HPP
