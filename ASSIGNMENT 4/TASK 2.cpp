#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {}
};

class Student : virtual public Person {
protected:
    string programme;
    float cgpa;

public:
    Student(string n, int i, string p, string pr, float c)
        : Person(n, i, p), programme(pr), cgpa(c) {}
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p), department(d), salary(s) {}
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string pr, float c, string d, double s)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {}
};

class Fellowship {
protected:
    double amount;

public:
    Fellowship(double a) {
        amount = a;
    }
};

class ResearchScholar : public Student {
private:
    Fellowship fellowship;

public:
    ResearchScholar(string n, int i, string p,
                    string pr, float c, double f)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          fellowship(f) {}
};

int main() {
    TeachingAssistant ta("Ravi", 101, "9876543210",
                         "CSE", 8.5, "Computer Science", 30000);

    ResearchScholar rs("Arun", 102, "9876543211",
                       "CSE", 9.0, 15000);

    cout << "Teaching Assistant and Research Scholar created successfully";

    return 0;
}
