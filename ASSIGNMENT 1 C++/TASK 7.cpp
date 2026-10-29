
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int zone, hour;
    double balance;
    long long fare;

    cout << "Enter Zone (1-Inner, 2-Middle, 3-Outer): ";
    while (!(cin >> zone) || zone < 1 || zone > 3) {
        cout << "Invalid zone! Enter 1, 2 or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Hour (0-23): ";
    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour! Enter 0-23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Balance in Rupees: ";
    while (!(cin >> balance) || balance < 0) {
        cout << "Invalid balance! Enter a non-negative value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int baseFare;

    switch (zone) {
        case 1: baseFare = 1000; break;
        case 2: baseFare = 2000; break;
        case 3: baseFare = 3000; break;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    fare = baseFare;

    if (peak) {
        fare = fare + fare * 20 / 100;
    }

    long long balancePaise = (long long)(balance * 100 + 0.5);

    cout << fixed << setprecision(2);

    cout << "\n--- Metro Journey Report ---" << endl;

    if (balancePaise - fare >= 5000) {
        balancePaise = balancePaise - fare;

        cout << "Journey Allowed" << endl;
        cout << "Fare: Rs. "
             << fare / 100.0 << endl;
        cout << "Remaining Balance: Rs. "
             << balancePaise / 100.0 << endl;
    } else {
        cout << "Journey Denied" << endl;
        cout << "Minimum Rs. 50 must remain." << endl;
        cout << "Balance: Rs. "
             << balancePaise / 100.0 << endl;
    }

    return 0;
}

