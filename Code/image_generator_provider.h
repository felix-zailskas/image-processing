#ifndef IMAGE_GENERATOR_PROVIDER_H_
#define IMAGE_GENERATOR_PROVIDER_H_

#include "image_generator.h"

class ImageGeneratorProvider
{
    public:
        ImageGeneratorProvider() {};
        ~ImageGeneratorProvider() {
            if (image_generator != NULL) {
                free(image_generator);
            }
        }
        
        ImageGenerator get_image_generator() {
            if (image_generator == NULL) {
                image_generator = new ImageGenerator();
            }
            return *image_generator;
        }

    private:
        ImageGenerator *image_generator = NULL;
};

#endif
