#include <iostream>
#include <iomanip>
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
        for (int i = 0; i < n; ++i) {
            t += prices[i];
        }
        return t * (100 - discount) / 100;
    }
};

int main() {

    // (a) Direct object
    Cart c;
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);

    // (b) Pointer using ->
    Cart* p = &c;
    p->add("Oil", 180);

    // (c) Reference
    Cart& ref = c;
    ref.add("Sugar", 40);

    // (d) Dynamic object using new and delete
    Cart* dynamicCart = new Cart();
    dynamicCart->add("Milk", 50);
    cout << "Dynamic Cart Total: " << dynamicCart->total() << endl;
    delete dynamicCart;

    cout << fixed << setprecision(2);
    cout << "Main Cart Total: " << p->total() << endl;

    // Array of pointers to Cart objects
    Cart c1, c2, c3;
    c1.add("Rice", 100);
    c2.add("Dal", 200);
    c3.add("Oil", 300);

    Cart* carts[3] = { &c1, &c2, &c3 };

    Cart* highest = carts[0];

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total() > highest->total()) {
            highest = carts[i];
        }
    }

    cout << "Highest Cart Total: " << highest->total() << endl;

    return 0;
}
