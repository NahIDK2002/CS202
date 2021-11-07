#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

class BankAccount{
private:
    string accNumber="";
    string ownerName="";
    string ownerID="";
    double balance=0;
    
public:
    BankAccount(string accNum, string name, string id, double bal);
    void input();
    void output();

    //return 0: accepted
    //return 1: invalid amount
    bool deposit(double amount);

    // return 0: accepted
    // return 1: invalid amount
    // return 2: not enough balance
    int widthdraw(double amount);
    double checkBalance();

};

class SavingBankAccount : public BankAccount{
private:
    double rate=0;
    int period=0;
    int savingMonth=0;
    void addInterest();

public:
    SavingBankAccount();
    SavingBankAccount(string accNum, string name, string id, double bal, double interestRate, int per, int savingMon);
    void input();
    void output();

    // return 0: accepted
    // return 1: invalid amount
    // return 2: not enough saving month, the owner should create a new account
    int deposit(double amount);

    // return 0: accepted
    // return 1: invalid amount
    // return 2: not enough balance
    // return 3: not enough saving month
    int widthdraw(double amount);

    // return 0: accepted
    // return 1: invalid amount
    // return 2: not enough balance
    int widthdrawImmediately(double amount);
    double checkBalance();
    double checkInterest();
};

#endif