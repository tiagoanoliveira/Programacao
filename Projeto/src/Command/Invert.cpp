//
// Created by tiago-oliveira on 15-05-2025.
//
#include "Command/Invert.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        Invert::Invert() : Command("Invert") {}

        Invert::~Invert() {}

        Image *Invert::apply(Image *img) {
            if (img == nullptr) return nullptr;

            // Process each pixel in the image
            for (int y = 0; y < img->height(); ++y) {
                for (int x = 0; x < img->width(); ++x) {
                    Color original = img->at(x, y);
                    // Invert each RGB component by subtracting from 255
                    // This creates a negative effect
                    img->at(x, y) = Color(255 - original.red(),
                                          255 - original.green(),
                                          255 - original.blue());
                }
            }
            return img;
        }

        std::string Invert::toString() const {
            return name();
        }

    }
}
