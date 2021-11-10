#include "shape.h"

using namespace std;

int main(){
    Screen s;
    s.input();
    s.output();

    cout << "\n\nTotal area: " << s.totalArea() << "\n";;
    

    return 0;
}