
#include <iostream>
using namespace std;

class SavingsAccount
{
    double balance;
    double transactions[10];
    int count;
    int next;

public:
    SavingsAccount(double initial)
    {
        balance = initial;
        count = 0;
        next = 0;
    }

    void addTransaction(double amount)
    {
        balance += amount;

        transactions[next] = amount;

        next = (next + 1) % 10;

        if (count < 10)
        {
            count++;
        }
    }

    void display()
    {
        cout << "Balance: " << balance << endl;
        cout << "Last 10 transactions:" << endl;

        int start;

        if (count < 10)
            start = 0;
        else
            start = next;

        for (int i = 0; i < count; i++)
        {
            int index = (start + i) % 10;

            if (transactions[index] >= 0)
                cout << "Deposit: " << transactions[index] << endl;
            else
                cout << "Withdrawal: " << -transactions[index] << endl;
        }

        cout << "Element shifts: 0" << endl;
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

