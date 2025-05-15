#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Replace : public Command {
        public:
            Replace(Color c1, Color c2);

            ~Replace();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            Color c1;
            Color c2;
        };
    }
}

#endif //PROJECT_REPLACE_HPP
