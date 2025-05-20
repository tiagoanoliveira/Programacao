//
// Created by guilherme-nunes on 5/16/25.
//
#include "Command/Resize.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Resize::Resize(int x, int y, int w, int h) : Command("Resize"), x(x), y(y), w(w), h(h) {}

        Resize::~Resize() {}

        Image* Resize::apply(Image* img) {
            if (img == nullptr) return nullptr;

            Color fill = img->at(0, 0);
            Image* new_img = new Image(w, h, fill);

            for (int new_y = 0; new_y < h; ++new_y) {
                for (int new_x = 0; new_x < w; ++new_x) {
                    int old_x = x + new_x;
                    int old_y = y + new_y;
                    if (old_x >= 0 && old_x < img->width() && old_y >= 0 && old_y < img->height()) {
                        new_img->at(new_x, new_y) = img->at(old_x, old_y);
                    }

                }
            }

            delete img;
            return new_img;
        }

        std::string Resize::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " h:" << h << " w:" << w;
            return ss.str();
        }

    }
}



