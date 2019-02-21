#ifndef _BANKING_H_
#define _BANKING_H_

#include <iostream>
#include <string>
#include <map>
#include <fstream>

#define FILE_NAME "Accounts.txt"

class Account
{
private:
    std::string name;
    std::string surname;
    float balance;
    int account_nr;
    static int accounts;
public:
    Account();
    Account(std::string name, std::string surname, float balance);
    float getBalance(void);
    void setBalance(float newBalance);
    int getAccountNr(void);
    static void setNextAccountNr(int lastAccount);
    friend std::ostream& operator<<(std::ostream &o, Account &a);
    friend std::ofstream& operator<<(std::ofstream &o, Account &a);
    friend std::ifstream& operator>>(std::ifstream &o, Account &a);
};

class Bank
{
private:
    std::map<int, Account> b;
public:
    Bank();
    void open_account(std::string name, std::string surname, float balance);
    void balance_enquiry(int acc_nr);
    void deposit(int acc_nr, float deposit);
    void withdrawal(int acc_nr, float amount);
    void close_account(int acc_nr);
    void show_accounts(void);
    ~Bank();
};
#endif // _BANKING_H_
