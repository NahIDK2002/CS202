#include "date.h"

using namespace std;

int main()
{
	Date d1; 				// Current date: 2/11/2012
	Date d2(2012); 			// 1/1/2012;
	Date d3(2012, 8);		// 01/08/2012
	Date d4(2012, 10, 17); 	// 17/10/2012
	Date d5(d2);
	Date d6;
	d6=d3;

	d6=d3.Tomorrow();
	d5=d6.Yesterday();
	
	cout<<(d6==d4);
	cout<<(d6!=d4);
	cout<<(d6>=d4);
	cout<<(d6<=d4);
	cout<<(d6>d4);
	cout<<(d6<d4);

	d3=d2+1;
	d2=d3-2;
	cout << d4++ << "\n";
	cout << ++d2 << "\n";
	cout << d5-- << "\n";
	cout << --d6 << "\n";

	cout<<d3;
	cin>>d4;
	
	// cout<<(int)d3;			// from the first day of current year
	
	// cout<<(long)d4; 		// from 1/1/1

	// Date d7;
	// d7+=7;
	// d2-=6;

	return 0;
}