#include "fraction.h"

using namespace std;

int main()
{
	Fraction f1, f2;					// 0/1
	Fraction f3(1,-7);					// -1/7
	Fraction f4(f3);					// Copy constructor
	Fraction f5=f2;						// Copy constructor
	Fraction f6, f7, f8;				// Default constructor
	f6=f3;								// Operator =

	f7=f1+f5;
	f8=f2-f4;
	f2=f3*f4;
	f5=f6/f3;
	

	cout<< (f2==f3) << "\n";
	cout<< (f3!=f1) << "\n";
	cout<< (f2>=f5) << "\n";
	cout<< (f2>f5) << "\n";
	cout<< (f5<=f3) << "\n";
	cout<< (f5<f3) << "\n";


	f1=f2+3;
	f3=-7+f1;
	f5=7*f3;
	f6=f4-6;
	
	cout<< f3 << "\n";
	cout<< f6 << "\n";

	f1+=f5;
	f6-=f7;
	f8*=f1;
	f8/=f2;

	cout<< f8++ << "\n";
	cout<< ++f7 << "\n";
	
	cout<< f8-- << "\n";
	cout<< --f7 << "\n";
	
	float f=(float)f3;				// 3/2 => 1.5

	return 0;
}