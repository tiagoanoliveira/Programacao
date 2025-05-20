//
// Created by guilherme-nunes on 5/20/25.
//

#ifndef MOVE_HPP
#define MOVE_HPP
#include "Command.hpp"
#include "Image.hpp"
namespace prog {
    namespace command {

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
