#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
            int x, y, w, h;
            Color color;
        public:
            Fill(int x, int y, int w, int h, Color color);

            ~Fill();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_FILL_HPP
