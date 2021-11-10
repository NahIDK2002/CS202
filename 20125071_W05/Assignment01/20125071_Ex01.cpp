#include "company.h"

using namespace std;

int main(){    
    Company comp;
    comp.input();
    cout << "\n\n";

    comp.output();

    cout << "Total salary: " << comp.totalSalary() <<"\n\n";
    vector<Employee *> mostPaid=comp.mostPaidEmployee();
    for (auto e:mostPaid){
        e->output();
        cout << "\n";
    }

    return 0;
}