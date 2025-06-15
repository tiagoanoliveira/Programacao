#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        /**
         * @brief The Replace class implements a command to replace one color with another in an image
         *
         * This class searches for all occurrences of a specified color (c1) in the image
         * and replaces them with a different color (c2).
         *
         * @param c1 The color to be replaced
         * @param c2 The replacement color
         */
        class Replace : public Command {
        private:
            Color c1;
            Color c2;
        public:
            Replace(Color c1, Color c2);

            ~Replace();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_REPLACE_HPP
