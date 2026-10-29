
#include <iostream>
using namespace std;

const int FARES[] = {1000, 2000, 3000, 6000};
const int MIN_BALANCE = 5000;

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) {
        balance = b;
    }

    bool canTravel(long long fare) {
        return balance - fare >= MIN_BALANCE;
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
};

class Pass {
private:
    int zone1, zone2;

public:
    Pass(int z1, int z2) {
        zone1 = z1;
        zone2 = z2;
    }

    bool coversZone(int zone) {
        return zone == zone1 || zone == zone2;
    }
};

long long calculateFare(int zone, int hour, bool weekend) {
    if (zone < 1 || zone > 4)
        return -1;

    long long fare = FARES[zone - 1];

    bool peak = ((hour >= 8 && hour < 10) ||
                 (hour >= 17 && hour < 20));

    if (weekend) {
        fare = fare - fare * 10 / 100;
    } else if (peak) {
        fare = fare + fare * 20 / 100;
    }

    return fare;
}

int main() {
    SmartCard card(20000);

    int zone, hour, weekend;
    int z1, z2;

    cout << "Zones: 1-Inner, 2-Middle, 3-Outer, 4-Airport" << endl;
    cout << "Enter zone: ";
    cin >> zone;

    cout << "Enter hour (0-23): ";
    cin >> hour;

    cout << "Weekend? (1-Yes, 0-No): ";
    cin >> weekend;

    cout << "Choose first pass zone (1-4): ";
    cin >> z1;

    cout << "Choose second pass zone (1-4): ";
    cin >> z2;

    if (hour < 0 || hour > 23 ||
        (weekend != 0 && weekend != 1) ||
        z1 < 1 || z1 > 4 || z2 < 1 || z2 > 4 ||
        z1 == z2) {
        cout << "Invalid input" << endl;
        return 0;
    }

    Pass monthlyPass(z1, z2);

    if (monthlyPass.coversZone(zone)) {
        cout << "Monthly pass used. No fare charged." << endl;
    } else {
        long long fare = calculateFare(zone, hour, weekend);

        if (fare == -1) {
            cout << "Invalid zone" << endl;
        } else {
            card.deduct(fare);
        }
    }

    return 0;
}

