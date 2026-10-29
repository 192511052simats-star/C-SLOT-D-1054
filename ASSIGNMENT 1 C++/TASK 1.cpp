#include <iostream>
using namespace std;

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) {
        balance = b;
    }

    bool canTravel(long long fare) {
        return balance - fare >= 5000;
    }

    void deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
            cout << "Journey Allowed" << endl;
            cout << "Balance: Rs." << balance / 100
                 << "." << (balance % 100 < 10 ? "0" : "")
                 << balance % 100 << endl;
        } else {
            cout << "Journey Denied" << endl;
            cout << "Balance: Rs." << balance / 100
                 << "." << (balance % 100 < 10 ? "0" : "")
                 << balance % 100 << endl;
        }
    }
};

int main() {
    SmartCard card(10000);

    card.deduct(1000);
    card.deduct(6000);

    return 0;
}
