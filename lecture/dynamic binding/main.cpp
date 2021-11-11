#include "shape.h"

using namespace std;

int main(){
    Screen s;
    s.input();
    s.output();

    cout << "Total area: " << s.totalArea() << "\n";;
    

    return 0;
}