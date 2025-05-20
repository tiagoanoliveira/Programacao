//
// Created by guilherme-nunes on 5/17/25.
//
#include "Command.hpp"
#include "Image.hpp"

#ifndef CROP_HPP
#define CROP_HPP
namespace prog {
    namespace command {
        /**
         * @brief The Crop class implements a command to extract a rectangular portion of an image
         *
         * This class allows extracting a rectangular region of the image defined by
         * the coordinates (x,y) as the top-left corner and dimensions width (w) and height (h).
         * The resulting image will contain only the specified portion.
         */
        class Crop : public Command {
        private:
            int x, y, w, h;
        public:
            /**
             * @brief Constructor for the Crop command
             *
             * @param x X-coordinate of the top-left corner of the area to crop
             * @param y Y-coordinate of the top-left corner of the area to crop
             * @param w Width of the area to crop
             * @param h Height of the area to crop
             */
            Crop(int x, int y, int w, int h);

            ~Crop();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}
#endif //CROP_HPP
