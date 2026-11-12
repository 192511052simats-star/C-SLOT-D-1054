#include <iostream>
using namespace std;

int& highestMark(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

int& wrongReference()
{
    int x = 50;
    return x;
}

int main()
{
    int marks[] = {75, 88, 92, 80, 85};
    int size = 5;

    cout << "Highest mark before moderation: "
         << highestMark(marks, size) << endl;

    highestMark(marks, size) += 2;

    cout << "Highest mark after moderation: "
         << highestMark(marks, size) << endl;

    return 0;
}
