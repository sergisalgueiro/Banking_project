#include <iostream>
#include <string>

#include "Banking.h"
using namespace std;

// Account class
Account::Account(string name, string surname, float balance)
{
    this->name = name;
    this->surname = surname;
    this->balance = balance;
}

float Account::getBalance(void)
{
    return this->balance;
}

void Account::setBalance(int newBalance)
{
    this->balance = newBalance;
    return;
}

ostream& operator<<(ostream &o, Account &a)
{
    o<<"Name: "<<a.name<<"\nSurname: "<<a.surname<<"\nBalance: "<<a.balance;
    return o;
}

int Account::accounts = 0;

// Bank class
