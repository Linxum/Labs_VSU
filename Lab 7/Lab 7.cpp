//Дан список пользователей портала с указанием номера телефона, логина и длительности регистрации на сайте в днях, 
//а также количество отправленных сообщений и роль пользователя.Все есть 4 типа ролей : user, admin, read - only user, moderator.
//Вывести номера телефонов и логины пользователей, отправивших больше всего сообщений в каждой категории ролей.
//Если таких пользователей в одной категории несколько, вывести всех.
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum user_name
{
    user,
    admin,
    read_only,
    moderator
};

struct user_info
{
    string phone;
    string login;
    int time = 0;
    int messages = 0;
    user_name role;
};

struct output
{
    user_name role_output;
    string phone_output;
    string login_output;
};

user_name code(string input)
{
    user_name returning;
    if (input == "user")
    {
        returning = user;
    }
    else if (input == "admin")
    {
        returning = admin;
    }
    else if (input == "read-only")
    {
        returning = read_only;
    }
    else if (input == "moderator")
    {
        returning = moderator;
    }
    return returning;
}

string decode(int input)
{
    string returning;
    switch (input)
    {
    case user:
        returning = "user";
        break;
    case admin:
        returning = "admin";
        break;
    case read_only:
        returning = "read-only";
        break;
    case moderator:
        returning = "moderator";
        break;
    }
    return returning;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    user_info users[100];
    output out[100];
    int n;
    string name_role;
    cout << "Количество пользователей:" << endl; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите данные " << i + 1 << "-го пользователя (номер телефона, логин, время со дня регистрации, кол-во сообщений и роль): " << endl;
        cout << "Роли: user, admin, read-only, moderator" << endl;
        cin >> users[i].phone;
        cin >> users[i].login;
        cin >> users[i].time;
        cin >> users[i].messages;
        cin >> name_role;
        users[i].role = code(name_role);
    }

    int max_messages[4] = { 0, 0, 0, 0 };
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        user_name current_role = users[i].role;
        switch (current_role)
        {
        case user:
            if (users[i].messages > max_messages[0])
            {
                max_messages[0] = users[i].messages;
            }
            break;
        case admin:
            if (users[i].messages > max_messages[1])
            {
                max_messages[1] = users[i].messages;
            }
            break;
        case read_only:
            if (users[i].messages > max_messages[2])
            {
                max_messages[2] = users[i].messages;
            }
            break;
        case moderator:
            if (users[i].messages > max_messages[3])
            {
                max_messages[3] = users[i].messages;
            }
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        user_name current_role = users[i].role;
        switch (current_role)
        {
        case user:
            if (max_messages[0] == users[i].messages)
            {
                out[counter].login_output = users[i].login;
                out[counter].phone_output = users[i].phone;
                out[counter].role_output = users[i].role;
                counter++;
            }
            break;
        case admin:
            if (max_messages[1] == users[i].messages)
            {
                out[counter].login_output = users[i].login;
                out[counter].phone_output = users[i].phone;
                out[counter].role_output = users[i].role;
                counter++;

            }
            break;
        case read_only:
            if (max_messages[2] == users[i].messages)
            {
                out[counter].login_output = users[i].login;
                out[counter].phone_output = users[i].phone;
                out[counter].role_output = users[i].role;
                counter++;
            }
            break;
        case moderator:
            if (max_messages[3] == users[i].messages)
            {
                out[counter].login_output = users[i].login;
                out[counter].phone_output = users[i].phone;
                out[counter].role_output = users[i].role;
                counter++;
            }
            break;
        }
    }
   
    cout << endl << "Номера телефонов, логины  и роли пользователей с наибольшим количеством сообщений: " << endl;
    for (int i = 0; i < counter; i++)
    {
        cout << "Роль: " << decode(out[i].role_output) << ", номер телефона: " << out[i].phone_output << ", логин: " << out[i].login_output << endl;
    }
    cout << endl << "Количество сообщений: " << endl << "для user: " << max_messages[0] << endl << "для admin: " << max_messages[1] << endl << "для read-only: " << max_messages[2] << endl << "для moderator: " << max_messages[3] << endl;
}

