//#ifndef _BANKING_H_
//#define _BANKING_H_

#include <iostream>
#include <string>
#include <map>
class Account
{
private:
    std::string name;
    std::string surname;
    float balance;
    int account_nr;
    static int accounts;
public:
    Account(std::string name, std::string surname, float balance);
    float getBalance(void);
    void setBalance(int newBalance);
    friend std::ostream& operator<<(std::ostream &o, Account &a);
};

class Bank
{
private:
    std::map<int, Account> m;
public:
    Bank();
};
//#endif // _BANKING_H_
