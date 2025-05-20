//
// Created by guilherme-nunes on 5/20/25.
//

#ifndef ADD_HPP
#define ADD_HPP
#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        class Add : public Command {
        private:
            std::string filename;
            int r, g, b;
            int x, y;
        public:
            Add(const std::string& filename, int r, int g, int b, int x, int y);
            ~Add();

            Image* apply(Image* img) override;
            std::string toString() const override;
        };

    }
}
#endif //ADD_HPP
