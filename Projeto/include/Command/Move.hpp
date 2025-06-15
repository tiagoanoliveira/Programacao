//
// Created by guilherme-nunes on 5/20/25.
//

#ifndef MOVE_HPP
#define MOVE_HPP
#include "Command.hpp"
#include "Image.hpp"
namespace prog {
    namespace command {
        /**
         * @brief The Move class implements a command to relocate the image content with padding
         *
         * This class moves the entire image content by x pixels horizontally and y pixels vertically.
         * Unlike Slide, pixels moved outside the boundaries are lost, and the vacated areas
         * are typically filled with a background color.
         *
         * @param x Amount of horizontal movement in pixels (positive: right, negative: left)
         * @param y Amount of vertical movement in pixels (positive: down, negative: up)
         */
        class Move : public Command {
        private:
            int x,y;
        public:
            Move(int  x, int y);

            ~Move();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}
#endif //MOVE_HPP
