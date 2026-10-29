
#include <iostream>
using namespace std;

int getFare(int zone, int hour) {
    int fare;

    switch (zone) {
        case 1: fare = 1000; break;
        case 2: fare = 2000; break;
        case 3: fare = 3000; break;
        default: return -1;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare = fare + fare * 20 / 100;

    return fare;
}

int main() {
    int zones[5] = {1, 2, 3, 3, 2};
    int hours[5] = {7, 8, 10, 17, 20};
    long long total = 0;

    cout << "Journey Test Results\n";

    for (int i = 0; i < 5; i++) {
        int fare = getFare(zones[i], hours[i]);

        cout << "Journey " << i + 1
             << ": Rs. " << fare / 100
             << ".";

        if (fare % 100 < 10)
            cout << "0";

        cout << fare % 100 << endl;
        total = total + fare;
    }

    cout << "Total Fare: Rs. "
         << total / 100 << ".";

    if (total % 100 < 10)
        cout << "0";

    cout << total % 100 << endl;

    return 0;
}

