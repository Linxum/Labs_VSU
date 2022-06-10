#include <iostream>
#include <Windows.h>

using namespace std;

void time(char *beg_time, char *end_time)
{
    int sum = ((end_time[0] * 10 + end_time[1]) * 60 + end_time[3] * 10 + end_time[4]) - ((beg_time[0] * 10 + beg_time[1]) * 60 + beg_time[3] * 10 + beg_time[4]);
    cout << "Итого:" << sum * 5 + 50;
}

void time(int min)
{
    cout << "Итого: " << min * 5 + 50;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char beg_time[6], end_time[6];
    int min = 0;
    cout << "Минуты или время? (0 - минуты, 1 - время): " << endl;
    bool flag;
    cin >> flag;
    if (flag)
    {
        cout << "Введи время: ";
        cin >> beg_time;
        cin >> end_time;
        time(beg_time, end_time);
    }
    else
    {
        cout << "Введи кол-во минут: ";
        cin >> min;
        time(min);
    }
}
