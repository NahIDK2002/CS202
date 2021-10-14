#include "fraction.h"

using namespace std;

int main(){
    try{
        Fraction a,b;
        readFile(a,b,"input.txt");

        a.add(b);
        cout << "Add: ";
        a.display();
        cout << "\n";

        a.substract(b);
        cout << "Substract: ";
        a.display();
        cout << "\n";

        a.multiply(b);
        cout << "Multiply: ";
        a.display();
        cout << "\n";

        try {
            a.divide(b);
            cout << "Divide: ";
            a.display();
            cout << "\n"; 
        }
        catch(string msg){
            cout << msg << "\n";
        }
        

        int resultComp = a.compare(b);
        cout << "a";
        switch (resultComp)
        {
        case -1:
            cout << " < b\n";
            break;

        case 0:
            cout << " = b\n";
            break;
        
        default:
            cout << " > b\n";
            break;
        }

        cout << "a.isPositive: " << a.isPositive() << "\n";
        cout << "a.isNegative: " << a.isNegative() << "\n";
        cout << "a.isZero: " << a.isZero() << "\n";
    }
    catch (string msg){
        cout << msg << "\n";
    }

    return 0;
}