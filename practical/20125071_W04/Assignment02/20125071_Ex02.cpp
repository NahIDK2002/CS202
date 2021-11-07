#include "bank.h"

using namespace std;

int main(){
    SavingBankAccount acc1("7795", "Willie", "6950", 1938000,4.326,4,50);

    cout <<"First account:\n";
    cout << setprecision(12);
    acc1.output();
    cout << "Balance: " << acc1.checkBalance() << "\n";
    cout << "Check interest: " << acc1.checkInterest() << "\n\n";
    
    double depositAmount = 50000;
    cout << "Deposit " << depositAmount << ": " << acc1.deposit(depositAmount) << "\n";
    cout << "Balance: " << acc1.checkBalance() << "\n";
    cout << "Check interest: " << acc1.checkInterest() << "\n\n";

    double withdrawAmount = 20000;
    cout << "Widthdraw " << withdrawAmount << ": " << acc1.widthdraw(withdrawAmount) << "\n";
    cout << "Balance: " << acc1.checkBalance() << "\n";
    cout << "Check interest: " << acc1.checkInterest() << "\n\n";

    double withdrawImmediatelyAmount = 200000;
    cout << "Widthdraw immediately " << withdrawImmediatelyAmount << ": " << acc1.widthdrawImmediately(withdrawImmediatelyAmount) << "\n";
    cout << "Balance: " << acc1.checkBalance() << "\n";
    cout << "Check interest: " << acc1.checkInterest() << "\n\n";

    cout << "\nSecond account:\n";

    SavingBankAccount acc2;
    acc2.input();

    acc2.output();
    cout << "Balance: " << acc2.checkBalance() << "\n";
    cout << "Check interest: " << acc2.checkInterest() << "\n\n";
    
    cout << "Deposit " << depositAmount << ": " << acc2.deposit(depositAmount) << "\n";
    cout << "Balance: " << acc2.checkBalance() << "\n";
    cout << "Check interest: " << acc2.checkInterest() << "\n\n";

    cout << "Widthdraw " << withdrawAmount << ": " << acc2.widthdraw(withdrawAmount) << "\n";
    cout << "Balance: " << acc2.checkBalance() << "\n";
    cout << "Check interest: " << acc2.checkInterest() << "\n\n";

    cout << "Widthdraw immediately " << withdrawImmediatelyAmount << ": " << acc2.widthdrawImmediately(withdrawImmediatelyAmount) << "\n";
    cout << "Balance: " << acc2.checkBalance() << "\n";
    cout << "Check interest: " << acc2.checkInterest() << "\n\n";

    return 0;
}