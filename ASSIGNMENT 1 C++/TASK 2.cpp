
#include <iostream>
using namespace std;

const int INNER_FARE = 1000;
const int MIDDLE_FARE = 2000;
const int OUTER_FARE = 3000;

const int PEAK_SURCHARGE_PERCENT = 20;
const long MIN_BALANCE_PAISE = 5000;

int main() {
    int zone = 3;
    int fare = 0;

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
            cout << "Invalid Zone";
            return 0;
    }

    int surcharge = fare * PEAK_SURCHARGE_PERCENT / 100;
    int totalFare = fare + surcharge;

    cout << "Base Fare: Rs. " << fare / 100 << endl;
    cout << "Peak Surcharge: Rs. " << surcharge / 100 << endl;
    cout << "Total Fare: Rs. " << totalFare / 100 << endl;
    cout << "Minimum Balance: Rs. "
         << MIN_BALANCE_PAISE / 100 << endl;

    return 0;
}

