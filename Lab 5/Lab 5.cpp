//Дан список пользователей портала с указанием номера телефона, логина и длительности
//регистрации на сайте в днях, а также количество отправленных сообщений.Вывести
//номера телефонов и логины пользователей, отправивших больше всего сообщений.
#include <Windows.h>
#include <iostream>

using namespace std;

struct user
{
    string phone;
    string login;
    int time;
    int messages;
};

struct output
{
    string phone_output;
    string login_output;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    user users[100];
    output out[100];
    int n;
    cout << "Количество пользователей:" << endl; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите данные " << i + 1 << "-го пользователя (номер телефона, логин, время со дня регистрации и кол-во сообщений): " << endl;
        cin >> users[i].phone;
        cin >> users[i].login;
        cin >> users[i].time;
        cin >> users[i].messages;
    }

    int max = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < users[i].messages)
        {
            max = users[i].messages;
        }

    }
    for (int i = 0; i < n; i++)
    {
        if (max == users[i].messages)
        {
            out[count].phone_output = users[i].phone;
            out[count].login_output = users[i].login;
            count++;
        }
    }

    cout << endl << "Номера телефонов и логины пользователей с наибольшим количеством сообщений: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << out[i].phone_output << " " << out[i].login_output << endl;
    }
    cout << endl << "Количество сообщений: " << max;
}

