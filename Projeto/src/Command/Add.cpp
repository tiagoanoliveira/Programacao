//
// Created by guilherme-nunes on 5/20/25.
//
#include "Image.hpp"
#include "Command/Add.hpp"
#include "PNG.hpp"
#include <sstream>
namespace prog {
    namespace command{
        Add::Add(const std::string& filename, int r, int g, int b, int x, int y)
                : Command("Add"), filename(filename), r(r), g(g), b(b), x(x), y(y) {}

        Add::~Add() {}

        Image* Add::apply(Image* img) {
            if (img == nullptr) return nullptr;

            // Load the overlay image from the specified file
            Image* new_img = loadFromPNG(filename);
            if(new_img == nullptr) return img;

            // Create neutral color for transparency check
            Color neutral(r,g,b);
            int width = new_img->width();
            int height = new_img->height();
            int original_width = img->width();
            int original_height = img->height();

            // Iterate through each pixel of the overlay image
            for (int col = 0; col < height; ++col) {
                for (int row = 0; row < width; ++row) {
                    // Calculate position in the base image
                    int new_x = (row + x);
                    int new_y = (col + y);

                    // Check if the position is within the base image bounds
                    if(new_x < original_width && new_y < original_height){
                        Color pixel = new_img->at(row,col);
                        // Only add non-neutral pixels (transparency effect)
                        if(pixel != neutral){
                            img->at(new_x,new_y) = new_img->at(row,col);
                        }
                    }
                }
            }
            delete new_img;
            return img;
        }
        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename << " r:" << r << " g:" << g << " b:" << b << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}