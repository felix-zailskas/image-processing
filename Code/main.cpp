#include "image_generator_provider.h"
#include "paths.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int get_rgb(const string s) {
    if (s.length() > 3) return -1;

    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return -1;
    }
    
    stringstream rgbstream(s);
    int rgb = 0;
    rgbstream >> rgb;
    if (rgb < 0 || rgb > 255) {
        return -1;
    }

    return rgb;
}

void user_input_mode(int argc, char const *argv[]) {
    if (argc < 4) {
        cout << "Please provide the source file path, destination file name and filter to apply!" << endl;
        return;
    }

    string src = argv[1];
    string dest = IMAGE_OUTPUT + argv[2];
    string filter = argv[3];

    for_each(filter.begin(), filter.end(), [](char & c) {
        c = ::tolower(c);
    });

    ImageGeneratorProvider provider = ImageGeneratorProvider();


    if (!filter.compare("color")) {
        if (argc < 7) {
            cout << "Please provide RGB values for the color filter." << endl;
            return;
        }
        int r = get_rgb(argv[4]);
        int g = get_rgb(argv[5]);
        int b = get_rgb(argv[6]);
        if (r == -1 || g == -1 || b == -1) {
            cout << "Valid rgb values are integers between 0 and 255!" << endl;
            return;
        }
        cout << "Processing..." << endl;
        provider.get_image_generator().apply_color_filter(src, dest, Triple(r, g, b));
        cout << "Color filter (" << r << "," << g << "," << b << ") applied" << endl;
    }

    if (!filter.compare("invert")) {
        cout << "Processing..." << endl;
        provider.get_image_generator().apply_inverted_filter(src, dest);    
        cout << "Inverted filter applied" << endl;
    }

    cout << "Image stored at: " << dest << endl;

}

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        user_input_mode(argc, argv);
        return 0;
    }

    ImageGeneratorProvider provider = ImageGeneratorProvider();
    string src = IMAGE_DIRECTORY + "split.ppm";
    string dest = IMAGE_OUTPUT + "manual.ppm";

    cout << "processing..." << endl;
    provider.get_image_generator().generate_ppm_image(src, RGB_SPLIT, 400, 400);
    cout << "image created" << endl;
    provider.get_image_generator().apply_inverted_filter(src, dest);
    cout << "filter applied" << endl;

    
    return 0;
}
