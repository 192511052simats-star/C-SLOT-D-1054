#include <iostream>
#include <string>
using namespace std;

class Staff {
protected:
    string name;
    int id;

public:
    Staff(string n, int i) {
        name = n;
        id = i;
    }

    virtual double pay() = 0;

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << pay() << endl;
    }

    virtual ~Staff() {}
};

class Professor : public Staff {
private:
    double basic;
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i) {
        basic = b;
        research = r;
    }

    double pay() {
        return basic + basic * 0.42 + research;
    }
};

class LabAssistant : public Staff {
private:
    double basic;

public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i) {
        basic = b;
    }

    double pay() {
        return basic + basic * 0.42;
    }
};

class GuestFaculty : public Staff {
private:
    double hours;
    double rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i) {
        hours = h;
        rate = r;
    }

    double pay() {
        return hours * rate;
    }
};

int main() {
    Staff *s[3];

    s[0] = new Professor("Ravi", 101, 30000, 5000);
    s[1] = new LabAssistant("Kumar", 102, 20000);
    s[2] = new GuestFaculty("Arun", 103, 40, 500);

    for (int i = 0; i < 3; i++) {
        s[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete s[i];
    }

    return 0;
}
