#include <iostream>
#include <cstring>
using namespace std;

class Text {
private:
    char* data;

public:
    // Constructor
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& t) {
        cout << "Copy constructor called" << endl;

        data = new char[strlen(t.data) + 1];
        strcpy(data, t.data);
    }

    // Copy assignment operator
    Text& operator=(const Text& t) {
        if (this != &t) {
            char* temp = new char[strlen(t.data) + 1];
            strcpy(temp, t.data);

            delete[] data;
            data = temp;
        }

        return *this;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }

    // Concatenation operator
    Text operator+(const Text& t) const {
        char* temp = new char[strlen(data) + strlen(t.data) + 1];

        strcpy(temp, data);
        strcat(temp, t.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& t) const {
        return strcmp(data, t.data) == 0;
    }

    // Not equal operator
    bool operator!=(const Text& t) const {
        return strcmp(data, t.data) != 0;
    }

    // Stream insertion operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }
};

int main() {
    Text a("Hello");
    Text b("World");
    Text c("Welcome");

    // Concatenation
    Text result = a + b + c;

    cout << "Concatenated Text: " << result << endl;

    // Comparison
    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;

    // Assignment
    Text d;
    d = a;

    cout << "Assigned Text: " << d << endl;

    // Self-assignment
    a = a;
    cout << "Self Assignment: " << a << endl;

    // Empty text
    Text empty;
    cout << "Empty Text: [" << empty << "]" << endl;

    // Long message
    Text longMessage("This is a long SMS gateway message");
    cout << "Long Message: " << longMessage << endl;

    return 0;
}
