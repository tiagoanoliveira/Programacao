//
// Created by guilherme-nunes on 5/17/25.
//
#include "Command.hpp"
#include "Image.hpp"

#ifndef CROP_HPP
#define CROP_HPP
namespace prog {
    namespace command {
        class Crop : public Command {
        private:
            int x, y, w, h;
        public:
            Crop(int x, int y, int w, int h);

            ~Crop();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}
#endif //CROP_HPP
