#include <iostream>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account Destructor\n";
    }
};

class SeniorAccount : public Account {
private:
    double* history;

public:
    SeniorAccount() {
        history = new double[100];
        cout << "SeniorAccount Constructor\n";
    }

    double rate() const {
        return 4.0;
    }

    ~SeniorAccount() {
        delete[] history;
        cout << "SeniorAccount Destructor\n";
    }
};

int main() {
    Account* accounts[2];

    accounts[0] = new Account();
    accounts[1] = new SeniorAccount();

    for (int i = 0; i < 2; i++) {
        cout << accounts[i]->rate() << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete accounts[i];
    }

    return 0;
}
