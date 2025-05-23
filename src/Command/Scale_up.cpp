//
// Created by guilherme-nunes on 5/16/25.
//
#include "Command/Scale_up.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Scale_up::Scale_up(int x, int y) : Command("Scale_up"), x(x), y(y) {}

        Scale_up::~Scale_up() {}

        Image *Scale_up::apply(Image *img) {
            if (img == nullptr) return nullptr;

            // Calculate new dimensions by multiplying original size by scaling factors
            int new_width = img->width() * x;
            int new_height = img->height() * y;

            Image *new_img = new Image(new_width, new_height);

            // Process each pixel in the original image
            for (int old_y = 0; old_y < img->height(); ++old_y) {
                for (int old_x = 0; old_x < img->width(); ++old_x) {
                    Color pixel = img->at(old_x, old_y);

                    // Replicate each pixel into an x by y block in the new image
                    for (int dy = 0; dy < y; ++dy) {
                        for (int dx = 0; dx < x; ++dx) {
                            // Calculate position in scaled image
                            new_img->at(old_x * x + dx, old_y * y + dy) = pixel;
                        }
                    }
                }
            }

            delete img;
            return new_img;
        }

        std::string Scale_up::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}