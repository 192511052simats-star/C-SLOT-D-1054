#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n;
    double discount;

public:
    Cart() {
        n = 0;
        discount = 0;
    }

    Cart& add(string item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;
        for (int i = 0; i < n; ++i)
            t += prices[i];

        return t * (100 - discount) / 100;
    }
};

int main() {
    Cart c;

    c.add("Rice", 60)
     .add("Dal", 120)
     .setDiscount(10);

    Cart* p = &c;
    p->add("Oil", 180);

    cout << fixed << setprecision(2)
         << p->total() << '\n';

    return 0;
}
