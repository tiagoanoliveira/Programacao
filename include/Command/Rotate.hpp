//
// Created by guilherme-nunes on 5/18/25.
//

#ifndef ROTATE_HPP
#define ROTATE_HPP
#include "Command.hpp"
#include "Image.hpp"
namespace prog {
    namespace command {

        class Rotate : public Command {
        private:
            std::string direction;
        public:
            Rotate(const std::string& direction);
            ~Rotate();

            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}
#endif //ROTATE_HPP
