
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    long long journeys[] = {20000, 500000, 3000000};
    long long farePaise = 3600;
    double fareRupees = 36.00;

    for (int i = 0; i < 3; i++) {
        long long totalPaise = journeys[i] * farePaise;
        double totalDouble = journeys[i] * fareRupees;
        double totalInteger = totalPaise / 100.0;

        cout << "\nJourneys: " << journeys[i] << endl;
        cout << fixed << setprecision(2);

        cout << "Double total: Rs " << totalDouble << endl;
        cout << "Integer-paise total: Rs " << totalInteger << endl;
        cout << "Difference: Rs "
             << (totalDouble - totalInteger) << endl;

        if (totalPaise > INT_MAX)
            cout << "int: Overflow risk" << endl;
        else
            cout << "int: Safe for this total" << endl;
    }

    return 0;
}

