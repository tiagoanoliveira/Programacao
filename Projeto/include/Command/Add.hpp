//
// Created by guilherme-nunes on 5/20/25.
//

#ifndef ADD_HPP
#define ADD_HPP
#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        /**
         * @brief The Add class implements a command to add/overlay another image onto the current image
         *
         * This class loads an image from a specified file and overlays it onto the current image
         * at a specified position (x,y). The overlay can be tinted with RGB color values before
         * being applied to the base image.
         *
         * @param filename Path to the image file to be added/overlaid
         * @param r Red color component for tinting the overlay image (0-255)
         * @param g Green color component for tinting the overlay image (0-255)
         * @param b Blue color component for tinting the overlay image (0-255)
         * @param x X-coordinate where the overlay image will be positioned
         * @param y Y-coordinate where the overlay image will be positioned
         */
        class Add : public Command {
        private:
            std::string filename;
            int r, g, b;
            int x, y;
        public:
            Add(const std::string& filename, int r, int g, int b, int x, int y);

            ~Add();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}
#endif //ADD_HPP
