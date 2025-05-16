//
// Created by guilherme-nunes on 5/16/25.
//

#ifndef PROJECT_RESIZE_HPP
#define PROJECT_RESIZE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        class Resize : public Command {
        private:
            int x, y, w, h;
        public:
            Resize(int x, int y, int w, int h);

            ~Resize();

            Image* apply(Image* img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_RESIZE_HPP

