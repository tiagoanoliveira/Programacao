#ifndef PROJECT_HMIRROR_HPP
#define PROJECT_HMIRROR_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
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
