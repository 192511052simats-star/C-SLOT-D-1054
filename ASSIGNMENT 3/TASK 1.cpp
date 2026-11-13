
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

    static int validateCopies(int c) {
        if (c < 0)
            throw invalid_argument("Invalid number of copies");
        return c;
    }

public:
    // Default constructor
    Book() : Book("", "Unknown", 0) {}

    // Overloaded constructor
    explicit Book(string t) : Book(t, "Unknown", 1) {}

    // Parameterized constructor
    Book(string t, string a, int c)
        : title(t), author(a), copies(validateCopies(c)) {}

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << "------------------" << endl;
    }
};

int main() {
    try {
        Book b1;
        Book b2("C++ Programming");
        Book b3("Python", "James", 5);

        b1.display();
        b2.display();
        b3.display();

        Book b4("Java", "John", -5);
        b4.display();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

