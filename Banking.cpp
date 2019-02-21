#include <iostream>
#include "Banking.h"

using namespace std;

// Account class
Account::Account(){}
Account::Account(string name, string surname, float balance)
{
    this->name = name;
    this->surname = surname;
    this->balance = balance;
    this->account_nr = accounts++;
}

float Account::getBalance(void)
{
    return this->balance;
}

void Account::setBalance(float newBalance)
{
    this->balance = newBalance;
    return;
}

int Account::getAccountNr(void)
{
    return this->account_nr;
}

void Account::setNextAccountNr(int lastAccount)
{
    accounts = lastAccount;
}

ostream& operator<<(ostream &o, Account &a)
{
    o<<"Account nr.: "<<a.account_nr<<"\nName: "<<a.name<<"\nSurname: "<<a.surname<<"\nBalance: "<<a.balance;
    return o;
}
ofstream& operator<<(ofstream &o, Account &a)
{
    o<<a.account_nr<<endl;
    o<<a.name<<endl;
    o<<a.surname<<endl;
    o<<a.balance<<endl;
    return o;
}

ifstream& operator>>(ifstream &i, Account &a)
{
    i>>a.account_nr;
    i>>a.name;
    i>>a.surname;
    i>>a.balance;
    return i;
}

int Account::accounts = 1;

// Bank class
Bank::Bank()
{
    ifstream infile;
    int lastNum;
    Account account;
    infile.open(FILE_NAME);
    if (infile)
    {
        while(!infile.eof())
        {
            infile>>account;
            b.insert(pair<int, Account>(account.getAccountNr(), account));
        }
        lastNum = account.getAccountNr() + 1;
    }
    else
    {
        lastNum = 1;
        cout<<"No File found."<<endl;
    }
    Account::setNextAccountNr(lastNum);
    infile.close();
}

void Bank::open_account(string name, string surname, float balance)
{
    cout<<"\n\nOPEN ACCOUNT:"<<endl;
    // Create account object
    Account ac(name, surname, balance);
    b.insert(pair<int, Account>(ac.getAccountNr(), ac));
    //Write to file
    ofstream outfile(FILE_NAME, ios::app);
    outfile<<ac;
    outfile.close();
    // Show in console
    cout<<ac<<endl;
    return;
}

void Bank::balance_enquiry(int acc_nr)
{
    map<int, Account>::iterator itr=b.find(acc_nr);
    if (itr != b.end()) //Meaning it found a match
    {
        cout<<"\n\n"<<itr->second<<endl;
    }
    else
    {
        cout<<"\n\nERROR: Account number does not match any existing account."<<endl;
    }
    return;
}

void Bank::deposit(int acc_nr, float deposit)
{
    map<int, Account>::iterator itr=b.find(acc_nr);
    if (itr != b.end()) //Meaning it found a match
    {
        float balance = itr->second.getBalance();
        itr->second.setBalance(balance + deposit);
        cout<<"\n\nBalance: "<<balance<< " -> "<<itr->second.getBalance()<<endl;
    }
    else
    {
        cout<<"\n\nERROR: Account number does not match any existing account."<<endl;
    }
    return;
}

void Bank::withdrawal(int acc_nr, float amount)
{
    map<int, Account>::iterator itr=b.find(acc_nr);
    if (itr != b.end()) //Meaning it found a match
    {
        float balance = itr->second.getBalance();
        itr->second.setBalance(balance - amount);
        cout<<"\n\nBalance: "<<balance<< " -> "<<itr->second.getBalance()<<endl;
    }
    else
    {
        cout<<"\n\nERROR: Account number does not match any existing account."<<endl;
    }
}

void Bank::close_account(int acc_nr)
{
    map<int, Account>::iterator itr=b.find(acc_nr);
    if (itr != b.end()) //Meaning it found a match
    {
        cout<<"\n\nAccount "<<itr->first<<" deleted."<<endl;
        cout<<itr->second<<endl;
        b.erase(acc_nr);
    }
    else
    {
        cout<<"\n\nERROR: Account number does not match any existing account."<<endl;
    }
    return;
}

void Bank::show_accounts()
{
    if (!b.empty())
    {
        map<int, Account>::iterator itr;
        for (itr=b.begin();itr!=b.end();itr++)
        {
            cout<<endl<<itr->second<<endl;
        }
    }
    else
    {
        cout<<"\n\nERROR: No accounts in the bank"<<endl;
    }
    return;
}

Bank::~Bank()
{
    // Copy all the account to file before closing
    ofstream outfile(FILE_NAME, ios::trunc);
    if (!b.empty())
    {
        map<int, Account>::iterator itr;
        for (itr=b.begin();itr!=b.end();itr++)
        {
            outfile<<itr->second;
        }
    }
    outfile.close();
}
