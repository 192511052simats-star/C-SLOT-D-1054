
#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 3;

    cout << x + y * 2 << endl;
    cout << (x + y) * 2 << endl;
    cout << x++ << endl;
    cout << ++x << endl;
    cout << x - y << endl;
    cout << x / y << endl;
    cout << x % y << endl;
    cout << (x > y ? x : y) << endl;

    for (int i = 1; i <= 3; i++) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}

