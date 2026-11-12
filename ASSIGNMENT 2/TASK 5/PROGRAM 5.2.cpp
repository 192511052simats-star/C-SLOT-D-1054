
#include <iostream>
#include <string>

class BusTicket {
    static int issued;
    static const int CAPACITY = 3;
    int seat;
    std::string name;

public:
    BusTicket(const std::string& n) : seat(0), name(n)
    {
        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
    }

    static int count()
    {
        return issued;
    }

    void print() const
    {
        std::cout << name << ": ";

        if (seat != 0)
            std::cout << "Seat " << seat;
        else
            std::cout << "Waiting";

        std::cout << '\n';
    }
};

int BusTicket::issued = 0;

int main()
{
    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (int i = 0; i < 4; i++)
    {
        trip[i].print();
    }

    std::cout << "Issued: " << BusTicket::count() << '\n';

    return 0;
}

