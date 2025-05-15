//
// Created by tiago-oliveira on 15-05-2025.
//
#include "Command/VMirror.hpp"
#include "Image.hpp"
#include <sstream>
#include <algorithm>

namespace prog {
    namespace command {

        VMirror::VMirror() : Command("v_mirror") {}

        VMirror::~VMirror() {}

        Image *VMirror::apply(Image *img) {
            if (!img) return nullptr;

            int width = img->width();
            int height = img->height();

            for (int x = 0; x < width; ++x) {
                for (int y = 0; y < height / 2; ++y) {
                    std::swap(img->at(x, y), img->at(x, height - 1 - y));
                }
            }

            return img;
        }

        std::string VMirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
