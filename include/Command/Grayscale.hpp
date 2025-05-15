#ifndef PROJECT_GRAYSCALE_HPP
#define PROJECT_GRAYSCALE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Grayscale : public Command {
        public:
            Grayscale();

            ~Grayscale();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}
#endif //PROJECT_GRAYSCALE_HPP
