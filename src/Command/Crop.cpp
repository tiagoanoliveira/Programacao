    //
    // Created by guilherme-nunes on 5/17/25.
    //
    #include "Command/Crop.hpp"
    #include "Image.hpp"
    #include <sstream>
    namespace prog {
        namespace command {

            Crop::Crop(int x, int y, int w, int h) : Command("Crop"), x(x), y(y), w(w), h(h) {}

            Crop::~Crop() {}

            Image* Crop::apply(Image* img) {
                if (img == nullptr) return nullptr;

                // Use top-left pixel as fill color for areas outside the crop region
                Color fill = img->at(0, 0);
                // Create new image with crop dimensions
                Image* new_img = new Image(w, h, fill);

                // Fill the cropped image by copying from the specified region
                for (int new_y = 0; new_y < h; ++new_y) {
                    for (int new_x = 0; new_x < w; ++new_x) {
                        // Calculate corresponding position in original image
                        int old_x = x + new_x;
                        int old_y = y + new_y;

                        // Only copy if the source position exists within original image bounds
                        if (old_x >= 0 && old_x < img->width() &&
                            old_y >= 0 && old_y < img->height()) {
                            new_img->at(new_x, new_y) = img->at(old_x, old_y);
                            }
                        // Pixels outside original bounds keep the fill color
                    }
                }
                delete img;
                return new_img;
            }

            std::string Crop::toString() const {
                std::ostringstream ss;
                ss << name() << " x:" << x << " y:" << y << " h:" << h << " w:" << w;
                return ss.str();
            }
        }
    }