//
// Created by tiago-oliveira on 15-05-2025.
//
#include "Command/Grayscale.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Grayscale::Grayscale() : Command("to_gray_scale") {}

        Grayscale::~Grayscale() {}

        Image *Grayscale::apply(Image *img) {
            if (!img) return nullptr;

            int width = img->width();
            int height = img->height();

            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    Color &pixel = img->at(x, y);
                    unsigned char v = (pixel.red() + pixel.green() + pixel.blue()) / 3;
                    pixel = Color(v, v, v);
                }
            }
            return img;
        }


        std::string Grayscale::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
