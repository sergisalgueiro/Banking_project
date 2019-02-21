#include <iostream>
#include "Banking.h"

using namespace std;

int main()
{
    Bank b;
    int menu;
    int account_nr;
    string name, surname;
    float in_balance;
    float amount;
    do
    {
        cout<<"\nAvailable options:";
        cout<<"\n\t1. Open account.";
        cout<<"\n\t2. Balance enquiry.";
        cout<<"\n\t3. Deposit.";
        cout<<"\n\t4. Withdrawal.";
        cout<<"\n\t5. Close account.";
        cout<<"\n\t6. Show all accounts.";
        cout<<"\n\t7. Quit.";
        cout<<"\nSelect option: ";
        cin>>menu;
        switch (menu)
        {
        case 1:
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter surname: ";
            cin>>surname;
            cout<<"Enter initial balance: ";
            cin>>in_balance;
            b.open_account(name, surname, in_balance);
            break;
        case 2:
            cout<<"Enter account number: ";
            cin>>account_nr;
            b.balance_enquiry(account_nr);
            break;
        case 3:
            cout<<"Enter account number: ";
            cin>>account_nr;
            cout<<"Enter amount to deposit: ";
            cin>>amount;
            b.deposit(account_nr, amount);
            break;
        case 4:
            cout<<"Enter account number: ";
            cin>>account_nr;
            cout<<"Enter amount to withdraw: ";
            cin>>amount;
            b.withdrawal(account_nr, amount);
            break;
        case 5:
            cout<<"Enter account number to be closed: ";
            cin>>account_nr;
            b.close_account(account_nr);
            break;
        case 6:
            b.show_accounts();
            break;
        case 7:
            cout<<"Exiting";
            break;
        default:
            cout<<"Command unknown";
            break;
        }
    }while(menu!=7);
    return 0;
}
