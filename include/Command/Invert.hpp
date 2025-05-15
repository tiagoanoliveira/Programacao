#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            Invert();

            ~Invert();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_INVERT_HPP
