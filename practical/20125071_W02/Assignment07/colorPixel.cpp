#include "colorPixel.h"

using namespace std;

ColorPixel::ColorPixel(){
    red=blue=green=0;
}

ColorPixel::ColorPixel(int r, int g, int b){
    if (r<0) red=0;
    else if (r>255) red=255;
    else red=r;

    if (g<0) green=0;
    else if (g>255) green=255;
    else green = g;

    if(b<0) blue=0;
    else if (b>255) blue=255;
    else blue=b;
}

ColorPixel::ColorPixel(int colorCode){
    red=colorCode & 0xFF0000;
    red>>=16;
    green=colorCode& 0x00FF00;
    green>>=8;
    blue = colorCode & 0x0000FF;
}

ColorPixel::ColorPixel(string color){
    for (auto c:color){
        c= ::tolower(c);
    }
    if (color=="black"){
        red=blue=green=0;
    }
    else if (color=="gray"){
        red=blue=green=128;
    }
    else if (color=="silver"){
        red=blue=green=192;
    }
    else if (color=="white"){
        red=blue=green=255;
    }
    else if (color=="blue"){
        red=green=0;
        blue=255;
    }
    else if (color=="aqua"){
        red=0;
        green=blue=255;
    }
    else if (color=="green"){
        red=blue=0;
        green=128;
    }
    else if (color=="lime"){
        red=blue=0;
        green=255;
    }
    else if (color=="yellow"){
        red=green=255;
        blue=0;
    }
    else if (color=="red")   {
        red=255;
        green=blue=0;
    }
    else if (color=="purple"){
        red=blue=128;
        green=0;
    }
    else{
        throw "Sorry! I can't understand!\n";
    }
}

ColorPixel::ColorPixel(const ColorPixel &other){
    red=other.red;
    green=other.green;
    blue = other.blue;
}

ColorPixel::~ColorPixel(){
    cout << "Delete successfully!\n";
}

void ColorPixel::display(){
    cout << "R: " << dec << red << "\n";
    cout << "G: " << dec << green << "\n";
    cout << "B: " << dec << blue << "\n";
    int colorCode=(red<<16) + (green<<8) + blue;
    cout << showbase << internal << setfill('0');
    cout << "Color codes: " << hex << setw(8) << colorCode << "\n";
}