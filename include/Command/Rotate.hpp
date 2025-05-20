//
// Created by guilherme-nunes on 5/18/25.
//

#ifndef ROTATE_HPP
#define ROTATE_HPP
#include "Command.hpp"
#include "Image.hpp"
namespace prog {
    namespace command {
        /**
         * @brief The Rotate class implements a command to rotate an image in a specified direction
         *
         * This class rotates the entire image in the direction specified (typically "left" or "right"),
         * producing a new image with swapped width and height dimensions.
         */
        class Rotate : public Command {
        private:
            std::string direction;
        public:
            /**
             * @brief Constructor for the Rotate command
             *
             * @param direction The direction to rotate the image (typically "left" or "right")
             */
            Rotate(const std::string& direction);

            ~Rotate();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}
#endif //ROTATE_HPP
