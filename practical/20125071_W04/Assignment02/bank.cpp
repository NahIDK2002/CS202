#include "bank.h"

using namespace std;

BankAccount::BankAccount(string accNum, string name, string id, double bal){
    accNumber = accNum;
    ownerName = name;
    ownerID = id;
    balance = bal;
}

void BankAccount::input(){
    cin.clear();
    fflush(stdin);

    cout << "Input account number: ";
    getline(cin,accNumber);

    cout << "Input name of owner: ";
    getline(cin,ownerName);

    cout << "Input social ID of owner: ";
    getline(cin,ownerID);

    cout << "Input balance: ";
    cin >> balance;

    cin.clear();
    fflush(stdin);
}

void BankAccount::output(){
    cout << "Account number: " << accNumber << "\n";
    cout << "Name of owner: " << ownerName << "\n";
    cout << "Social ID of owner: " << ownerID << "\n";
    cout << "Current balance: " << balance << "\n";
}

bool BankAccount::deposit(double amount){
    if (amount<0) return 1;
    balance+=amount;
    return 0;
}

int BankAccount::widthdraw(double amount){
    if (amount<0) return 1;
    if (balance-amount<50000) return 2;

    balance-=amount;
    return 0;
}

double BankAccount::checkBalance(){
    return balance;
}

void SavingBankAccount::addInterest(){
    double balance = BankAccount::checkBalance();
    double interest = balance*pow(1+rate/100/(12/period),int(savingMonth/period));

    BankAccount::deposit(interest);    
}

SavingBankAccount::SavingBankAccount():
                    BankAccount("unknown","unknown","unknown",0), rate(0), period(0), savingMonth(0){}

SavingBankAccount::SavingBankAccount(string accNum, string name, string id, double bal, double interestRate, int per, int savingMon):
                    BankAccount(accNum, name, id, bal) {
    rate=interestRate;
    period=per;
    savingMonth=savingMon;

    addInterest();
}

void SavingBankAccount::input(){
    BankAccount::input();

    cin.clear();
    fflush(stdin);

    cout << "Input interest rate (in %/year): ";
    cin >> rate;

    cout << "Input period (in month): ";
    cin >> period;

    cout << "Input saving month: ";
    cin >> savingMonth;

    addInterest();

    cin.clear();
    fflush(stdin);
}

void SavingBankAccount::output(){
    cout << "Infomation of saving bank account:\n";
    BankAccount::output();

    cout << "Interest rate: " << rate << "%\n";
    cout << "Period: " << period << "\n";
    cout << "Saving month: " << savingMonth << "\n";
}

int SavingBankAccount::deposit(double amount){
    if (savingMonth<period) return 2;
    return BankAccount::deposit(amount);
}

int SavingBankAccount::widthdraw(double amount){
    if (savingMonth<period) return 3;
    return BankAccount::widthdraw(amount);
}

int SavingBankAccount::widthdrawImmediately(double amount){
    int error=BankAccount::widthdraw(amount);
    if (error) return error;
    period=1;
    savingMonth=0;
    rate=2;

    return 0;
}

double SavingBankAccount::checkBalance(){
    return BankAccount::checkBalance();
}

double SavingBankAccount::checkInterest(){
    return double(BankAccount::checkBalance()*(rate/100.0/12.0)*double(period));
}