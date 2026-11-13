#include <iostream>
#include <string>
using namespace std;

class Auditorium {
private:
    int rows, seatsPerRow;
    char** seats;
    string eventName;

public:
    // Dynamic constructor
    Auditorium(string name, int r, int s)
        : rows(r), seatsPerRow(s), eventName(name), seats(NULL) {

        cout << "Constructor: " << eventName << endl;

        if (rows > 0 && seatsPerRow > 0) {
            seats = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seats[i] = new char[seatsPerRow];

                for (int j = 0; j < seatsPerRow; j++) {
                    seats[i][j] = 'O';
                }
            }
        }
    }

    // Book a seat
    void bookSeat(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seatsPerRow &&
            seats != NULL && seats[r][s] == 'O') {

            seats[r][s] = 'X';
            cout << "Seat booked successfully" << endl;
        }
        else {
            cout << "Seat booking failed" << endl;
        }
    }

    // Cancel a seat
    void cancelSeat(int r, int s) {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seatsPerRow &&
            seats != NULL && seats[r][s] == 'X') {

            seats[r][s] = 'O';
            cout << "Seat cancelled successfully" << endl;
        }
        else {
            cout << "Seat cancellation failed" << endl;
        }
    }

    // Display seat map
    void display() {
        cout << "\nSeat Map: " << eventName << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seatsPerRow; j++) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Prevent copying
    Auditorium(const Auditorium&) = delete;
    Auditorium& operator=(const Auditorium&) = delete;

    // Destructor
    ~Auditorium() {
        if (seats != NULL) {
            for (int i = 0; i < rows; i++) {
                delete[] seats[i];
            }

            delete[] seats;
        }

        cout << "Destructor: " << eventName
             << " - Memory released" << endl;
    }
};

int main() {

    // Stack object
    Auditorium a1("College Event", 2, 3);

    a1.bookSeat(0, 1);
    a1.bookSeat(1, 2);
    a1.display();

    // Block-scope object
    {
        Auditorium a2("Music Event", 2, 2);

        a2.bookSeat(0, 0);
        a2.display();
    }

    // Heap object
    Auditorium* a3 = new Auditorium("Dance Event", 3, 3);

    a3->bookSeat(1, 1);
    a3->cancelSeat(1, 1);
    a3->display();

    delete a3;

    // Zero-row object
    Auditorium a4("Empty Event", 0, 5);

    return 0;
}
