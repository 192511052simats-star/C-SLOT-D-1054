#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Time {
private:
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    // Prefix increment
    Time& operator++() {
        ++seconds;
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time temp = *this;
        ++seconds;
        return temp;
    }

    // Equality operator
    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    // Less than operator
    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    void display() const {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;

        cout << h << ":"
             << (m < 10 ? "0" : "") << m << ":"
             << (s < 10 ? "0" : "") << s << endl;
    }
};

class Playlist {
private:
    vector<string> tracks;

public:
    Playlist() {
        tracks.push_back("Song 1");
        tracks.push_back("Song 2");
        tracks.push_back("Song 3");
    }

    // Non-const subscript
    string& operator[](int index) {
        if (index < 0 || index >= (int)tracks.size()) {
            throw out_of_range("Invalid playlist index");
        }

        return tracks[index];
    }

    // Const subscript
    const string& operator[](int index) const {
        if (index < 0 || index >= (int)tracks.size()) {
            throw out_of_range("Invalid playlist index");
        }

        return tracks[index];
    }

    int size() const {
        return (int)tracks.size();
    }
};

int main() {

    Time t(5);

    Time a = t++;
    Time b = ++t;

    cout << "Postfix value: ";
    a.display();

    cout << "Prefix value: ";
    b.display();

    cout << "Current value: ";
    t.display();

    cout << boolalpha;
    cout << "Equal: " << (a == b) << endl;
    cout << "Less: " << (a < b) << endl;

    Playlist playlist;

    cout << "\nPlaylist:" << endl;

    for (int i = 0; i < playlist.size(); i++) {
        cout << playlist[i] << endl;
    }

    try {
        cout << playlist[5] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    Time rollover(3599);
    ++rollover;

    cout << "\nAfter rollover: ";
    rollover.display();

    return 0;
}
