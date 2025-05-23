//
// Created by tiago-oliveira on 15-05-2025.
//
#include "Command/Fill.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Fill::Fill(int x, int y, int w, int h, const Color &color)
            : Command("fill"), x(x), y(y), w(w), h(h), color(color) {}

        Fill::~Fill() {}

        Image *Fill::apply(Image *img) {
            if (!img) return nullptr;

            int imgWidth = img->width();
            int imgHeight = img->height();

            // Iterate through the rectangular area to be filled
            // Starting at (x,y) and extending w pixels right and h pixels down
            for (int j = y; j < y + h; ++j) {
                for (int i = x; i < x + w; ++i) {
                    // Check if the current position is within image boundaries
                    if (i >= 0 && i < imgWidth && j >= 0 && j < imgHeight) {
                        // Fill the pixel with the specified color
                        img->at(i, j) = color;
                    }
                }
            }
            return img;
        }

        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " " << x << " " << y << " " << w << " " << h << " "
               << (int)color.red() << " " << (int)color.green() << " " << (int)color.blue();
            return ss.str();
        }
    }
}
