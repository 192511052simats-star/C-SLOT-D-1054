#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

public:
    SavingsAccount(int accNo, double initialBalance)
    {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
    }

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement();

    double getBalance()
    {
        return balance;
    }
};

// Deposit function defined outside class
void SavingsAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount" << endl;
        return;
    }

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
        }

        transactions[9] = amount;
    }

    cout << "Deposited: " << amount << endl;
}

// Withdraw function defined outside class
void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        cout << "Invalid withdrawal" << endl;
        return;
    }

    balance -= amount;

    if (count < 10)
    {
        transactions[count] = -amount;
        count++;
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            transactions[i] = transactions[i + 1];
        }

        transactions[9] = -amount;
    }

    cout << "Withdrawn: " << amount << endl;
}

// Mini statement function
void SavingsAccount::miniStatement()
{
    cout << "\nAccount Number: " << accountNumber << endl;
    cout << "Current Balance: " << balance << endl;

    cout << "\nLast Transactions:" << endl;

    for (int i = 0; i < count; i++)
    {
        if (transactions[i] >= 0)
            cout << "Deposit: " << transactions[i] << endl;
        else
            cout << "Withdrawal: " << -transactions[i] << endl;
    }
}

int main()
{
    SavingsAccount account(1001, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);
    account.deposit(1500);

    account.miniStatement();

    return 0;
}
