#include "fraction.h"

int main(){
    Fraction a;
    a.display();

    Fraction b(7);
    b.display();

    try{
        Fraction c(-1,2);
        c.display();

        Fraction d(c);
        d.display();
    }
    catch (const char* msg){
        cout << msg;
    }
    
    try{
        Fraction e("20/-30");
        e.display();
    }
    catch(const char *msg){
        cout << msg;
    }

    return 0;
}