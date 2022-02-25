#include <iostream>
#include <fstream>

#include "image_generator.h"

using namespace std;

const int WIDTH = 400;
const int HEIGHT = 400;

int main(int argc, char const *argv[]) {

    ImageGenerator image_generator = ImageGenerator(WIDTH, HEIGHT);

    // image_generator.generate_ppm_image("black.ppm", BLACK);
    // image_generator.generate_ppm_image("white.ppm", WHITE);
    // image_generator.generate_ppm_image("random.ppm", RANDOM);

    image_generator.generate_ppm_image("split.ppm", RGB_SPLIT);

    return 0;
}
