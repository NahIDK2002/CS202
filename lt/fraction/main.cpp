#include "fraction.h"

using namespace std;

int main(){
    Fraction a(8,9);
    Fraction b(8,9);
    Fraction x = 5+b;

    cout << ++a << "\n";
    cout << b++ << "\n";
    cout << b << "\n";

    cout << --a << "\n";
    cout << b-- << "\n";
    cout << b << "\n";
        
    return 0;
}