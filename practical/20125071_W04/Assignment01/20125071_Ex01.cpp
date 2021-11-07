#include "employee.h"

using namespace std;

int main(){
    OfficeEmployee o1("Tuomo");
    o1.output();
    cout << "Salary of o1: " << o1.salary() << "\n\n";

    OfficeEmployee o2("Juliette", 2);
    o2.output();
    cout << "Salary of o2: " << o2.salary() << "\n\n";

    OfficeEmployee o3("4804afe3755d4d4c8642b9dcf20bd2bb","Ferran",12);
    o3.output();
    cout << "Salary of o3: " << o3.salary() << "\n\n";

    OfficeEmployee o4("ed215a15899746fb928dcf590c8d650d","Cynwrig","7/11/2021",32);
    o4.output();
    cout << "Salary of o4: " << o4.salary() << "\n\n";

    OfficeEmployee o5("14e316357d084dc0a4186acffb3913a6","Aristeides","23/12/2020",45);
    o5.output();
    cout << "Salary of o5: " << o5.salary() << "\n\n";

    OfficeEmployee o6;
    o6.input();
    cout << "\n";
    o6.output();
    cout << "Salary of o6: " << o6.salary() << "\n\n";

    Worker w1("Yeong-Hui");
    w1.output();
    cout << "Salary of w1: " << w1.salary() << "\n\n";

    Worker w2("Meera", 12);
    w2.output();
    cout << "Salary of w2: " << w2.salary() << "\n\n";

    Worker w3("6577f06925174fd39692bdd5389c13d9", "Yehoyakhin", 24);
    w3.output();
    cout << "Salary of w3: " << w3.salary() << "\n\n";

    Worker w4("56df1c0a5bea4844859f8222d0b61576", "Cruz", "23/4/2012", 15);
    w4.output();
    cout << "Salary of w4: " << w4.salary() << "\n\n";

    Worker w5("982f22e0bcc440b4b5a7ba4fb95cc876","Veronika", "16/12/2008", 102);
    w5.output();
    cout << "Salary of w5: " << w5.salary() << "\n\n";

    Worker w6;
    w6.input();
    cout << "\n";
    w6.output();
    cout << "Salary of w6: " << w6.salary() << "\n\n";

    system("pause");

    return 0;
}