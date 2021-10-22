#ifndef COLORPIXEL_H_
#define COLORPIXEL_H_

#include <iostream>
#include <iomanip>

using namespace std;

class ColorPixel{
    private:
        int red;
        int green;
        int blue;

    public:
        ColorPixel();
        ColorPixel(int r, int g, int b);
        ColorPixel(int colorCode);
        ColorPixel(string color);
        ColorPixel(const ColorPixel &other);
        ~ColorPixel();
        void display();
};

#endif