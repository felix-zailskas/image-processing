#include "image_generator.h"


ImageGenerator::ImageGenerator(int w, int h) {
    width = w;
    height = h;
}

void ImageGenerator::generate_ppm_image(string fname, InitType mode) {
    ofstream image;
    image.open("../Images/" + fname);

    srand(time(0));

    if (image.is_open()) {
        // place header info
        image << "P3" << endl;
        image << width << " " << height << endl;
        image << "255" << endl;

        int slope = height / width;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Color c;
                switch (mode) {
                case RANDOM:
                    c = Triple(rand() % 255, rand() % 255, rand() % 255);
                    break;
                case BLACK:
                    c = Triple(0, 0, 0);
                    break;
                case RGB_SPLIT:
                    // diagonals across the square
                    // bottom left to top right
                    if (y == -slope * x + height) {
                        c  = Triple(0, 0, 0); 
                        break;
                    }
                    // top left to bottom right
                    if (y == slope * x) {
                        c = Triple(0, 0, 0);
                        break;
                    }
                    
                    // fill in left triangle
                    if ((y > slope * x) && (y < -slope * x + height)) {
                        c = Triple(255, 0, 0);
                        break;
                    }
                    // fill in the right triangle
                    if ((y < slope * x) && (y > -slope * x + height)) {
                        c = Triple(0, 0, 255);
                        break;
                    }
                    // fill in the top triangle
                    if (x > y) {
                        c = Triple(0, 255, 0);
                        break;
                    }
                    // fill in the bottom triangle
                    if (x < y) {
                        c = Triple(150, 94, 19);
                        break;
                    }

                case WHITE:
                default:
                    c = Triple(255, 255, 255);
                    break;
                }

                image << c.r << " " << c.g << " " << c.b << endl;
            }
        }
    }

    image.close();
}