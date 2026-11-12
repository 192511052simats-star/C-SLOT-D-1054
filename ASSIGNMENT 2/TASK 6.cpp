
#include <iostream>

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b)
{
    // TODO 1
    int time1 = a.h * 60 + a.m;
    int time2 = b.h * 60 + b.m;

    int difference = time1 - time2;

    if (difference < 0)
        difference = -difference;

    return difference;
}

bool earlier(const Time& a, const Time& b)
{
    // TODO 2
    if (a.h < b.h)
        return true;

    if (a.h == b.h && a.m < b.m)
        return true;

    return false;
}

int main()
{
    Time departure(9, 45), arrival(13, 10);

    std::cout << minutesBetween(departure, arrival) << ' '
              << std::boolalpha
              << earlier(arrival, departure) << '\n';

    return 0;
}

