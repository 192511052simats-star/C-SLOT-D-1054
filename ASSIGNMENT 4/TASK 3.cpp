#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Address {
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {
        cout << "Address Constructor\n";
    }

    ~Address() {
        cout << "Address Destructor\n";
    }

    string str() const {
        stringstream ss;
        ss << pin;
        return city + "-" + ss.str();
    }
};

class Course {
    string courseName;

public:
    Course(string c) : courseName(c) {
        cout << "Course Constructor\n";
    }

    ~Course() {
        cout << "Course Destructor\n";
    }
};

class Person {
protected:
    string name;
    int age;
    Address home;

public:
    Person(string n, int a, string city, int pin)
        : name(n), age(a), home(city, pin) {
        cout << "Person Constructor\n";
    }

    ~Person() {
        cout << "Person Destructor\n";
    }
};

class Student : virtual public Person {
protected:
    long long regNo;
    Course course;

public:
    Student(string n, int a, long long r,
            string city, int pin, string c)
        : Person(n, a, city, pin),
          regNo(r), course(c) {
        cout << "Student Constructor\n";
    }

    ~Student() {
        cout << "Student Destructor\n";
    }
};

class Staff : virtual public Person {
protected:
    double salary;

public:
    Staff(string n, int a, string city, int pin, double s)
        : Person(n, a, city, pin), salary(s) {
        cout << "Staff Constructor\n";
    }

    ~Staff() {
        cout << "Staff Destructor\n";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int a, long long r,
                      string city, int pin, string c, double s)
        : Person(n, a, city, pin),
          Student(n, a, r, city, pin, c),
          Staff(n, a, city, pin, s) {
        cout << "TeachingAssistant Constructor\n";
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant Destructor\n";
    }
};

int main() {
    cout << "--- Student Object ---\n";
    {
        Student s("Kavya", 19, 192311001,
                  "Salem", 636001, "CSE");
    }

    cout << "\n--- Staff Object ---\n";
    {
        Staff st("Ravi", 35, "Chennai", 600001, 40000);
    }

    cout << "\n--- TeachingAssistant Object ---\n";
    {
        TeachingAssistant ta("Arun", 25, 192311002,
                             "Chennai", 600002, "CSE", 25000);
    }

    return 0;
}
