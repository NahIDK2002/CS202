#include "triangle.h"

using namespace std;

void readFile(Triangle &ABC, string file){
    ifstream f;
    f.open(file);
    if (!f.is_open()){
        f.close();
        throw "Error! Can't open file!";
    }

    double xa,ya,xb,yb,xc,yc;
    f >> xa >> ya >> xb >> yb >> xc >> yc;
    ABC = Triangle(xa,ya,xb,yb,xc,yc);

    f.close();
}