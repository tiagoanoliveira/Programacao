#ifndef PROJECT_HMIRROR_HPP
#define PROJECT_HMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        /**
         * @brief The HMirror class implements a command to horizontally mirror an image
         *
         * This class flips the image horizontally (left to right), creating a mirror
         * effect where the left side becomes the right side and vice versa.
         */
        class HMirror : public Command {
        public:
            HMirror();

            ~HMirror();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}

#endif //PROJECT_HMIRROR_HPP
