#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        /**
         * @brief The Fill class implements a command to fill a rectangular area with a specific color
         *
         * This class allows filling a rectangular region within the image defined by
         * the coordinates (x,y) as the top-left corner and dimensions width (w) and height (h)
         * with a specified color.
         *
         * @param x X-coordinate of the top-left corner of the rectangle
         * @param y Y-coordinate of the top-left corner of the rectangle
         * @param w Width of the rectangle to be filled
         * @param h Height of the rectangle to be filled
         * @param color The color to fill the rectangular area with
         */
        class Fill : public Command {
        private:
            int x, y, w, h;
            Color color;
        public:
            Fill(int x, int y, int w, int h, const Color &color);

            ~Fill();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_FILL_HPP
