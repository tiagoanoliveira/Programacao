//
// Created by guilherme-nunes on 5/16/25.
//

#ifndef SCALE_UP_HPP
#define SCALE_UP_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        /**
         * @brief The Scale_up class implements a command to scale up an image by specified factors
         *
         * This class enlarges an image by multiplying its width by factor x and its height
         * by factor y. The resulting image will be larger than the original.
         */
        class Scale_up : public Command {
        private:
          int x , y;
        public:
            /**
             * @brief Constructor for the Scale_up command
             *
             * @param x Horizontal scaling factor (how many times to multiply the width)
             * @param y Vertical scaling factor (how many times to multiply the height)
             */
            Scale_up(int x, int y);

            ~Scale_up();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}







#endif //SCALE_UP_HPP
