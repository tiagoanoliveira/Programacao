//
// Created by guilherme-nunes on 5/16/25.
//

#ifndef PROJECT_RESIZE_HPP
#define PROJECT_RESIZE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        /**
         * @brief The Resize class implements a command to resize a specific area of an image
         *
         * This class allows resizing a rectangular area within the image defined by
         * the coordinates (x,y) as the starting point and new dimensions width (w) and height (h).
         * This typically creates a new image with the specified dimensions.
         *
         * @param x X-coordinate of the starting position
         * @param y Y-coordinate of the starting position
         * @param w New width for the resized image
         * @param h New height for the resized image
         */
        class Resize : public Command {
        private:
            int x, y, w, h;
        public:
            Resize(int x, int y, int w, int h);

            ~Resize();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_RESIZE_HPP

