//
// Created by guilherme-nunes on 5/18/25.
//
#include "Command/Rotate.hpp"
#include "Image.hpp"
#include <sstream>
namespace prog {
    namespace command {

        Rotate::Rotate(const std::string& direction)
            : Command("Rotate"), direction(direction) {}

        Rotate::~Rotate() {}

        Image* Rotate::apply(Image* img) {
            if (img == nullptr) return nullptr;

            int old_width = img->width();
            int old_height = img->height();
            Image* new_img = new Image(old_height, old_width, img->at(0, 0));

            for (int y = 0; y < old_height; ++y) {
                for (int x = 0; x < old_width; ++x) {
                    if (direction == "left") {
                        int new_x = y;
                        int new_y = old_width - 1 - x;
                        new_img->at(new_x, new_y) = img->at(x, y);
                    } else if (direction == "right") {
                        int new_x = old_height - 1 - y;
                        int new_y = x;
                        new_img->at(new_x, new_y) = img->at(x, y);
                    }
                }
            }

            delete img;
            return new_img;
        }

        std::string Rotate::toString() const {
            std::ostringstream ss;
            ss << name() << " direction: " << direction;
            return ss.str();
        }

    }
}