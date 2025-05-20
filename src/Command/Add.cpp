//
// Created by guilherme-nunes on 5/20/25.
//
#include "Image.hpp"
#include "Command/Add.hpp"
#include "PNG.hpp"
namespace prog {
    namespace command{
        Add::Add(const std::string& filename, int r, int g, int b, int x, int y)
                : Command("Add"), filename(filename), r(r), g(g), b(b), x(x), y(y) {}

        Add::~Add() {}

        Image* Add::apply(Image* img) {
            if (img == nullptr) return nullptr;
            Image* new_img = loadFromPNG(filename);
            if(new_img == nullptr) return img;
            Color neutral(r,g,b);
            int width = new_img->width();
            int height = new_img->height();
            int original_width = img->width();
            int original_height = img->height();
            for (int col = 0; col < height; ++col) {
                for (int row = 0; row < width; ++row) {
                    int new_x = (row + x);
                    int new_y = (col + y);
                    if(new_x < original_width && new_y < original_height){
                      Color pixel = new_img->at(row,col);
                      if(pixel != neutral){
                        img->at(new_x,new_y) = new_img->at(row,col);}
                    }

                }
            }
            delete new_img;
            return img;
        }
        std::string Add::toString() const {
            return name();
        }
    }
}