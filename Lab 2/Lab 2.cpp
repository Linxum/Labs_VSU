//Пусть дано n отрезков на интервале[A, B].Определите часть ин -
//тервала, который покрывается наибольшим количеством отрезков, Напи -
//шите функцию для определения количества отрезков, покрывающих задан -
//ный интервал.

#include<iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	double a, b;
	cin >> a >> b;
	cin >> n;
	double** dick = new double*[n];
	for (int i = 0; i < n; i++)
	{
		dick[i] = new double[2];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> dick[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Введи координаты " << i << endl;
		cin >> dick[i]
	}
}
