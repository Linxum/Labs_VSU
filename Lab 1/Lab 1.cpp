#include <iostream>
#include <Windows.h>

using namespace std;

int sum_digit(int elem)
{
    int temp = abs(elem);
    int sum = 0;
    while (temp != 0)
    {
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a, b;
    cout << "Размер матрицы (А и В):" << endl;
    cin >> a >> b;
    double **matrix = new double* [a];
    for (int i = 0; i < a; i++)
    {
        *(matrix + i) = new double[b];
    }
    cout << "Значения : " << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> *(*(matrix + i) + j);
        }
    }
    
    int counter = 0;
    double max = 0.0;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (*(*(matrix + i) + j) > max)
            {
                max = *(*(matrix + i) + j);
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (max == *(*(matrix + i) + j))
            {
                counter++;
            }
        }
    }

    if (counter > 1)
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < (b - 1); j++)
            {
                if ((sum_digit(*(*(matrix) + j)) + sum_digit(*(*(matrix + a - 1) + j))) > (sum_digit(*(*(matrix) + j + 1)) + sum_digit(*(*(matrix + a - 1) + j + 1))))
                {
                    for (int k = 0; k < a; k++)
                    {
                        swap(*(*(matrix + k - 1) + j), *(*(matrix + k - 1) + j + 1));
                    }
                }
            }
        }
    }

    cout << "Конечная матрица:" << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}
