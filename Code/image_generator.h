#ifndef IMAGE_GENERATOR_H_
#define IMAGE_GENERATOR_H_

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "triple.h"

using namespace std;

typedef enum InitType {
    RANDOM,
    WHITE,
    BLACK,
    RGB_SPLIT
} InitType;

class ImageGenerator
{
    public:
        ImageGenerator(int w, int h);

        void generate_ppm_image(string fname, InitType mode);
    
        int height;
        int width;
};

#endif
