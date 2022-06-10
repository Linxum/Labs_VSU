#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;
using std::swap;

double calculate_the_integral(int n, double a, double m, double x) {

    double result = 0;
    if (n == 1)
    {
        result = ((x * pow(a, m * x)) / (m * log(a))) - (pow(a, m * x) / (m * pow(log(a), 2)));
    }
    else if (n > 1)
    {
        result = ((pow(x, n) * pow(a, m * x)) / (n * log(a))) - ((n / (m * log(a))) * calculate_the_integral(n - 1, a, m, x));
    }

    return result;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SetConsoleOutputCP(1251);

    int n;
    double a, m, border_a, border_b;
    cout << "Введите n: ";
    cin >> n;
    cout << "\nВведите границу a: ";
    cin >> border_a;
    cout << "\nВведите границу b: ";
    cin >> border_b;
    cout << "\nВведите a: ";
    cin >> a;
    cout << "\nВведите m: ";
    cin >> m;

    double result = calculate_the_integral(n, a, m, border_b) - calculate_the_integral(n, a, m, border_a);
    cout << "\nРезультат: " << result;
}
