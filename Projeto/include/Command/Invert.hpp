#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        /**
         * @brief Class that implements a command to invert the colors of an image
         *
        * This class inverts all color values of each pixel in the image,
         * creating a negative effect where each RGB component is replaced
         * with its complement (255 - original value).
         */
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
