
#include <iostream>
using namespace std;

int main() {
    int fare = 30;
    double discount = 10.5;

    double result = fare - discount;

    cout << "Fare: " << fare << endl;
    cout << "Discount: " << discount << endl;
    cout << "Final Amount: " << result << endl;

    int x = 5;
    int y = 2;

    cout << "Integer Division: " << x / y << endl;
    cout << "Floating Division: "
         << (double)x / y << endl;

    return 0;
}

