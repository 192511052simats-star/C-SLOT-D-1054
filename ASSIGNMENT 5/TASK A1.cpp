
#include <iostream>
#include <string>
using namespace std;

class Bill {
protected:
    string patientName;
    int billId;

public:
    Bill(string name, int id) {
        patientName = name;
        billId = id;
    }

    virtual double total() const = 0;
    virtual string type() const = 0;

    virtual void print() const {
        cout << "Bill ID: " << billId << endl;
        cout << "Patient: " << patientName << endl;
        cout << "Bill Type: " << type() << endl;
        cout << "Total: Rs. " << total() << endl;
    }

    virtual ~Bill() {}
};

class OutPatientBill : public Bill {
    double consultation, tests;

public:
    OutPatientBill(string name, int id, double c, double t)
        : Bill(name, id) {
        consultation = c;
        tests = t;
    }

    double total() const {
        return consultation + tests;
    }

    string type() const {
        return "Outpatient";
    }
};

class InPatientBill : public Bill {
    int days;
    double roomCharge, procedures, medicines;

public:
    InPatientBill(string name, int id, int d,
                  double r, double p, double m)
        : Bill(name, id) {
        days = d;
        roomCharge = r;
        procedures = p;
        medicines = m;
    }

    double total() const {
        return days * roomCharge + procedures + medicines;
    }

    string type() const {
        return "Inpatient";
    }
};

class DayCareBill : public Bill {
    double packagePrice;

public:
    DayCareBill(string name, int id, double price)
        : Bill(name, id) {
        packagePrice = price;
    }

    double total() const {
        return packagePrice;
    }

    string type() const {
        return "Day Care";
    }
};

class EmergencyBill : public Bill {
    double baseCharge, timeCharge;

public:
    EmergencyBill(string name, int id, double base, double time)
        : Bill(name, id) {
        baseCharge = base;
        timeCharge = time;
    }

    double total() const {
        return baseCharge + timeCharge;
    }

    string type() const {
        return "Emergency";
    }
};

int main() {
    Bill* bills[4];

    bills[0] = new OutPatientBill("Ravi", 101, 500, 1200);
    bills[1] = new InPatientBill("Meena", 102, 3, 2500, 40000, 5000);
    bills[2] = new DayCareBill("Arun", 103, 15000);
    bills[3] = new EmergencyBill("Kumar", 104, 3000, 2000);

    double dayTotal = 0;
    int i;

    for (i = 0; i < 4; i++) {
        bills[i]->print();
        cout << endl;
        dayTotal += bills[i]->total();
    }

    cout << "Day Total: Rs. " << dayTotal << endl;

    for (i = 0; i < 4; i++) {
        delete bills[i];
    }

    return 0;
}

