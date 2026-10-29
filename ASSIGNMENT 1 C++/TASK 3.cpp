
#include <iostream>
#include <climits>
using namespace std;

int main() {
    bool isPeak = true;
    char zone = 'O';
    int fare = 3000;
    long long totalFare = 9000000000LL;
    unsigned int journeys = 1000;
    double discount = 10.5;

    cout << "Peak Time: " << isPeak << endl;
    cout << "Zone: " << zone << endl;
    cout << "Fare in Paise: " << fare << endl;
    cout << "Total Fare in Paise: " << totalFare << endl;
    cout << "Number of Journeys: " << journeys << endl;
    cout << "Discount: " << discount << "%" << endl;

    cout << "\nSize of int: " << sizeof(fare) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(totalFare)
         << " bytes" << endl;
    cout << "Maximum int value: " << INT_MAX << endl;

    if (totalFare > INT_MAX) {
        cout << "Use long long to avoid integer overflow." << endl;
    }

    return 0;
}

