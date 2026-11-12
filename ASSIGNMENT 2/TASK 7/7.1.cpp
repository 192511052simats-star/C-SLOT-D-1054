
#include <iostream>
using namespace std;

class SavingsAccount
{
    double balance;
    double transactions[10];
    int count;
    int shifts;

public:
    SavingsAccount(double initial)
    {
        balance = initial;
        count = 0;
        shifts = 0;
    }

    void addTransaction(double amount)
    {
        balance += amount;

        if (count < 10)
        {
            transactions[count] = amount;
            count++;
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                transactions[i] = transactions[i + 1];
                shifts++;
            }

            transactions[9] = amount;
        }
    }

    void display()
    {
        cout << "Balance: " << balance << endl;
        cout << "Last 10 transactions:" << endl;

        for (int i = 0; i < count; i++)
        {
            if (transactions[i] >= 0)
                cout << "Deposit: " << transactions[i] << endl;
            else
                cout << "Withdrawal: " << -transactions[i] << endl;
        }

        cout << "Element shifts: " << shifts << endl;
    }
};

int main()
{
    SavingsAccount account(5000);

    account.addTransaction(1000);
    account.addTransaction(-500);
    account.addTransaction(2000);
    account.addTransaction(-300);
    account.addTransaction(1500);
    account.addTransaction(-200);
    account.addTransaction(700);
    account.addTransaction(-100);
    account.addTransaction(900);
    account.addTransaction(-400);
    account.addTransaction(600);
    account.addTransaction(-250);

    account.display();

    return 0;
}

