#include "fraction.h"

using namespace std;

int main(){
    try{
        Fraction a,b;
        readFile(a,b,"input.txt");

        int num,denom;
        a.add(b);
        a.output(num,denom);
        cout << "Add: " << num << "/" << denom << "\n";

        a.substract(b);
        a.output(num,denom);
        cout << "Substract: " << num << "/" << denom << "\n";

        a.multiply(b);
        a.output(num,denom);
        cout << "Multiply: " << num << "/" << denom << "\n";

        try {
            a.divide(b);
            a.output(num,denom);
            cout << "Divide: " << num << "/" << denom << "\n"; 
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