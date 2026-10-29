
#include <iomanip>
#include <iostream>
using namespace std;

enum Zone { Inner, Middle, Outer };

const int BASE_PAISE[] = {1000, 2000, 3000};
const int PEAK_SURCHARGE_PERCENT = 20;
const long long MIN_BALANCE_PAISE = 5000;

long long fare(Zone z, bool peak) {
    int baseFare;

    switch (z) {
        case Inner:
            baseFare = BASE_PAISE[0];
            break;

        case Middle:
            baseFare = BASE_PAISE[1];
            break;

        case Outer:
            baseFare = BASE_PAISE[2];
            break;

        default:
            return -1;
    }

    if (peak)
        baseFare = baseFare +
                   baseFare * PEAK_SURCHARGE_PERCENT / 100;

    return baseFare;
}

bool canTravel(long long balance, long long f) {
    return f >= 0 && balance - f >= MIN_BALANCE_PAISE;
}

int main() {
    long long balance = 10000;

    struct Trip {
        Zone zone;
        bool peak;
    };

    Trip trips[] = {
        {Inner, false},
        {Outer, true},
        {Middle, false}
    };

    int n = sizeof(trips) / sizeof(trips[0]);

    for (int i = 0; i < n; i++) {
        long long f = fare(trips[i].zone, trips[i].peak);

        if (canTravel(balance, f)) {
            balance -= f;

            cout << "Fare Rs " << f / 100 << '.'
                 << setw(2) << setfill('0') << f % 100
                 << setfill(' ');
        } else {
            cout << "Denied (low balance)";
        }

        cout << " balance Rs " << balance / 100 << endl;
    }

    return 0;
}

