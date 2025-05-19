//
// Created by guilherme-nunes on 5/19/25.
//

#ifndef SLIDE_HPP
#define SLIDE_HPP
#include "Command.hpp"
#include "Image.hpp"
namespace prog {
    namespace command {

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
