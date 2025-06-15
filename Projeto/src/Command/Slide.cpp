//
// Created by guilherme-nunes on 5/19/25.
//
#include "Command/Slide.hpp"
#include "Image.hpp"
#include <sstream>
namespace prog {
    namespace command {

        Slide::Slide(int x, int y)
            : Command("Slide"), x(x), y(y) {}

        Slide::~Slide() {}

        Image* Slide::apply(Image* img) {
            if (img == nullptr) return nullptr;

            int width = img->width();
            int height = img->height();

            // Create new image with same dimensions, filled with background color
            Image* new_img = new Image(width, height, img->at(0, 0));

            // Process each pixel from the original image
            for (int col = 0; col < height; ++col) {
                for (int row = 0; row < width; ++row) {
                    // Calculate new position with wrapping using modulo operation
                    // This creates a cyclic/tiling effect where pixels wrap aroun
                    int new_x = (row + x ) % width;
                    int new_y = (col + y ) % height;

                    new_img->at(new_x,new_y) = img->at(row,col);
                }
            }

            delete img;
            return new_img;
        }

        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y;
            return ss.str();
        }

    }
}