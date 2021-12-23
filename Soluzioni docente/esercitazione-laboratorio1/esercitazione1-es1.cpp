#include <iostream>
#include <cstdlib>
#include <cmath>
const int N = 5;

using namespace std;

int main()
{
	int a[N] = {0, 23, 4, 10, 1}, b[N], c[N], d[N], i;

	for (i = 0; i < N; i++)
	{
		b[i] = pow(-1, i) * (i * 3);
	}

	for (i = 0; i < N; i++)
	{
		if (a[i] > b[i])
			d[i] = 1;
		else if (a[i] < b[i])
			d[i] = -1;
		else
			d[i] = 0;
	}
	cout << "Valori di a: ";
	for (i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl
		 << "Valori di b: ";
	for (i = 0; i < N; i++)
		cout << b[i] << " ";
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[N - 1 - i];
	cout << endl
		 << "Valori di c: ";
	for (i = 0; i < N; i++)
		cout << c[i] << " ";
	cout << endl
		 << "Valori di d: ";
	for (i = 0; i < N; i++)
		cout << d[i] << " ";
	return 0;
}
