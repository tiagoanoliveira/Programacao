//
// Created by guilherme-nunes on 5/19/25.
//

#ifndef SLIDE_HPP
#define SLIDE_HPP
#include "Command.hpp"
#include "Image.hpp"
namespace prog {
    namespace command {
        /**
         * @brief The Slide class implements a command to shift the image content in a cyclic manner
         *
         * This class shifts the entire image content by x pixels horizontally and y pixels vertically.
         * Pixels that would be moved outside the image boundaries reappear on the opposite edge,
         * creating a wrapping/tiling effect.
         *
         * @param x Amount of horizontal shift in pixels (positive: right, negative: left)
         * @param y Amount of vertical shift in pixels (positive: down, negative: up)
         */
        class Slide : public Command {
        private:
            int x,y;
        public:
            Slide(int  x, int y);

            ~Slide();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}
#endif //SLIDE_HPP
