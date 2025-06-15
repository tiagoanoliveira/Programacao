#ifndef PROJECT_VMIRROR_HPP
#define PROJECT_VMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        /**
         * @brief The VMirror class implements a command to vertically mirror an image
         *
         * This class flips the image vertically (top to bottom), creating a mirror
         * effect where the top side becomes the bottom side and vice versa.
         */
        class VMirror : public Command {
        public:
            VMirror();

            ~VMirror();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_VMIRROR_HPP
