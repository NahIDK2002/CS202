#include "fraction.h"

using namespace std;

int main(){
    Fraction a, b(7), c(2,5);
    a.print();
    b.print();
    c.print();

    Fraction d(c);
    d.print();
    
    return 0;
}