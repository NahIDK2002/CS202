#include "employee.h"

using namespace std;

int main(){
    OfficeEmployee officeE1("12345","Bui Le Gia Cat","12/12/2012","Ho Chi Minh city",5);
    officeE1.output();

    Worker worker("54321", "Bui Le Gia Cat", "10/10/2021", "Ho Chi Minh city", 15);
    worker.output();


    return 0;
}