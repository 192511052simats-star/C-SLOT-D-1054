#include <iostream>
using namespace std;

class Parcel
{
public:
    double weight;
    bool express;
    bool insured;

    Parcel(double w, bool e = false, bool i = false)
    {
        weight = w;
        express = e;
        insured = i;
    }
};

// Weight in grams
void charge(int grams)
{
    cout << "Integer grams function selected" << endl;
}

// Weight in kg
void charge(double kg, bool express = false, bool insured = false)
{
    double amount = kg * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    cout << "Double kg function selected: Rs." << amount << endl;
}

// Parcel object
void charge(Parcel p)
{
    double amount = p.weight * 50;

    if (p.express)
        amount += 30;

    if (p.insured)
        amount += 20;

    cout << "Parcel function selected: Rs." << amount << endl;
}

int main()
{
    cout << "Call 1: ";
    charge(2);

    cout << "Call 2: ";
    charge(2.0);

    cout << "Call 3: ";
    charge(2.0f);

    cout << "Call 4: ";
    charge(2.5, true);

    cout << "Call 5: ";
    charge(3.0, true, true);

    cout << "Call 6: ";
    Parcel p(4.0, false, true);
    charge(p);

    return 0;
}
