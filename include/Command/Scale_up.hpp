//
// Created by guilherme-nunes on 5/16/25.
//

#ifndef SCALE_UP_HPP
#define SCALE_UP_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Scale_up : public Command {
        private:
          int x , y;
        public:
            Scale_up(int x, int y);

            ~Scale_up();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}







#endif //SCALE_UP_HPP
