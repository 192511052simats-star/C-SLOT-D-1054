#include <iostream>
using namespace std;

const int INNER_FARE = 1000;
const int MIDDLE_FARE = 2000;
const int OUTER_FARE = 3000;
const int PEAK_PERCENT = 20;

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
            balance = balance - fare;
            cout << "Fare: Rs " << fare / 100 << endl;
            cout << "Balance: Rs " << balance / 100 << endl;
        } else {
            cout << "Journey denied: Low balance" << endl;
        }
    }

    long long getBalance() {
        return balance;
    }
};

long long calculateFare(int zone, bool peak) {
    long long fare;

    switch (zone) {
        case 1:
            fare = INNER_FARE;
            break;
        case 2:
            fare = MIDDLE_FARE;
            break;
        case 3:
            fare = OUTER_FARE;
            break;
        default:
            return -1;
    }

    if (peak) {
        fare = fare + fare * PEAK_PERCENT / 100;
    }

    return fare;
}

int main() {
    SmartCard card(10000);

    int zone;
    int hour;

    cout << "Enter zone (1-Inner, 2-Middle, 3-Outer): ";
    cin >> zone;

    cout << "Enter hour (0-23): ";
    cin >> hour;

    if (hour < 0 || hour > 23) {
        cout << "Invalid hour" << endl;
        return 0;
    }

    bool peak = ((hour >= 8 && hour < 10) ||
                 (hour >= 17 && hour < 20));

    long long fare = calculateFare(zone, peak);

    if (fare == -1) {
        cout << "Invalid zone" << endl;
    } else {
        card.deduct(fare);
    }

    return 0;
}
