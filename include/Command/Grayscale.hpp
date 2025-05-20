#ifndef PROJECT_GRAYSCALE_HPP
#define PROJECT_GRAYSCALE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        /**
         * @brief The Grayscale class implements a command to convert an image to grayscale
         *
         * This class transforms a color image into grayscale by replacing each
         * pixel's color with an appropriate gray tone, usually based on the
         * weighted average of the RGB components.
         */
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
