#include <iostream>
#include <Windows.h>

using std::cout;
using std::cin;

int main()
{
	int a, i, b;
	cin >> a;
	while (a < 0)
	{
		cin >> a;
	}
	b = a;
	while (a != 0)
	{
		cin >> a;
		if ((a < b) && (a > 0))
		{
			b = a;
		}
	}
	cout << b;
	return 0;
}
