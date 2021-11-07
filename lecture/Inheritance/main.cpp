#include "header.h"

using namespace std;

int main(){
    Derived x(5);
    Derived a(7);

    x.display();
    cout << "\n";
    a.display();
    cout << "\n\n";

    a=x;

    x.display();
    cout << "\n";
    a.display();

    return 0;
}