#include <iomanip>
#include <iostream>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    // TODO 1: Overload +
    Money operator+(const Money& m) const {
        return Money(0, paise + m.paise);
    }

    // Overload -
    Money operator-(const Money& m) const {
        return Money(0, paise - m.paise);
    }

    // Overload +=
    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    // TODO 2: Overload ==
    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    // Overload <
    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    // Overload <<
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long rupees = m.paise / 100;
        long long p = m.paise % 100;

        if (p < 0) p = -p;

        out << "Rs " << rupees << "."
            << setfill('0') << setw(2) << p
            << setfill(' ');

        return out;
    }

    // Overload >>
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;

        in >> rupees >> p;

        if (in) {
            m.paise = rupees * 100 + p;
        }

        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);

    Money c = a + b;

    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;

    // Paise carry test
    Money x(0, 75), y(0, 50);
    Money z = x + y;

    cout << z << endl;

    // Subtraction test
    Money d = Money(10) - Money(15);
    cout << d << endl;

    // Addition assignment
    x += y;
    cout << x << endl;

    return 0;
}
