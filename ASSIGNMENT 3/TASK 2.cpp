#include <iostream>
#include <string>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    // Parameterized constructor
    explicit Prescription(int count)
        : n(count), medicines(new string[count]) {}

    // TODO 1: Deep copy constructor
    Prescription(const Prescription& p)
        : n(p.n), medicines(new string[p.n]) {
        cout << "Copy constructor called" << endl;

        for (int i = 0; i < n; i++) {
            medicines[i] = p.medicines[i];
        }
    }

    // TODO 2: Copy assignment operator
    Prescription& operator=(const Prescription& p) {
        if (this != &p) {
            string* temp = new string[p.n];

            for (int i = 0; i < p.n; i++) {
                temp[i] = p.medicines[i];
            }

            delete[] medicines;
            medicines = temp;
            n = p.n;
        }

        return *this;
    }

    // TODO 3: Destructor
    ~Prescription() {
        delete[] medicines;
    }

    void set(int i, const string& m) {
        medicines[i] = m;
    }

    string get(int i) const {
        return medicines[i];
    }
};

int main() {
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;
    q.set(1, "Cetirizine");

    Prescription r(1);
    r = p;

    p.set(0, "Ibuprofen");

    cout << p.get(0) << ' ' << p.get(1)
         << " | " << q.get(0) << ' ' << q.get(1)
         << " | " << r.get(0) << ' ' << r.get(1) << endl;

    return 0;
}
