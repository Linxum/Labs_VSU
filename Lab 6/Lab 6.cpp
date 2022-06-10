//По данным, имеющимся в файле movie.dat, определить и вывести
//на экран название фильма, который был выпущен в заданном году и имел
//наибольшее число просмотров.Год выпуска вводится с клавиатуры.
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int name_len = 80;
const int director_len = 40;
const int country_len = 20;
const int count_year = 4;
const int count_views = 9;

struct movie
{
private:
    char name[name_len];
    char director[director_len];
    char country[country_len];
    int views;
    int year;
public:
    movie() = default;
    void input_from_txt(ifstream& file);
    void print();
    void print_to_txt(ofstream& file);
    bool condition(int max, int years);
    int get_views();
    int get_year();
};

void movie::input_from_txt(ifstream& file)
{
    file.getline(name, name_len);
    file.getline(director, director_len);
    file.getline(country, country_len);
    file >> views;
    file >> year;
    file.ignore();
    if (!file.eof())
    {
        char separator[name_len];
        file.ignore();
        file.getline(separator, name_len);
    }
}

void movie::print()
{
    cout << "Название: " << name << endl;
    cout << "Режисёр: " << director << endl;
    cout << "Страна: " << country << endl;
    cout << "Количество просмотров:" << views << endl;
    cout << "Год выпуска: " << year << endl;
}

void movie::print_to_txt(ofstream& file)
{
    file << name << '\n';
}

bool movie::condition(int max, int years)
{
    bool check = false;
    if (years == year)
    {
        if (max == views)
        {
            check = true;
        }
    }
    return check;
}

void bin_output(movie* movies, int n, int max, int years)
{
    ofstream bin_file("result.bin", ios::binary);
    for (int i = 0; i < n; i++)
    {
        if ((movies + i)->condition(max, years))
        {
            bin_file.write((char*)(movies + i), sizeof(movie));
            bin_file.flush();
        }
    }
    bin_file.close();
}

void txt_output(movie* movies, int n, int max, int years)
{
    ofstream txt_file("result.txt");
    for (int i = 0; i < n; i++)
    {
        if ((movies + i)->condition(max, years))
        {
            (movies + i)->print_to_txt(txt_file);
        }
    }
    txt_file.close();
}

int movie::get_views()
{
    return views;
}

int movie::get_year()
{
    return year;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    ifstream file_input("movie.dat");
    int n;
    file_input >> n;
    file_input.ignore();

    movie* movies = new movie[n];
    for (int i = 0; i < n; i++)
    {
        //movies[i] = movie(file_input);
        movies[i].input_from_txt(file_input);
    }
    file_input.close();

    cout << "Полученные данные из файла: " << endl;
    for (int i = 0; i < n; i++)
    {
        (movies + i)->print();
        cout << endl;
    }

    int max = 0;
    int years;
    cout << "Какой год? " << endl;
    cin >> years;
    
    for (int i = 0; i < n; i++)
    {
        if (years == movies[i].get_year())
        {
            if (max < movies[i].get_views())
            {
                max = movies[i].get_views();
            }
        }
    }
    
    int menu;
    cout << "В файл какого типа записать подходящие фильмы? " << endl << "1.bin" << endl << "2.txt" << endl << "Ваш выбор: ";
    cin >> menu;
    switch (menu)
    {
    case 1:
        bin_output(movies, n, max, years);
        cout << "Файл создан, данные записаны" << endl << endl;
        break;
    case 2:
        txt_output(movies, n, max, years);
        cout << "Файл создан, данные записаны" << endl << endl;
        return 0;
    default:
        cout << "Неверный выбор" << endl;
        break;
    }

    delete[] movies;

    ifstream bin_read("result.bin", ios::binary);
    movie st;
    while (bin_read.peek() != EOF)
    {
        bin_read.read((char*)&st, sizeof(movie));
        st.print();
    }
    bin_read.close();
}
