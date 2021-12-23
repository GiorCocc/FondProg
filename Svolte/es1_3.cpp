#include<iostream>
#include<math.h>
const int N = 3;

using namespace std;

int main() {
	float x1, x2, soglia;
	int n[N] = { 81,9,6 };
	soglia = 0.00001;
	for (int i = 0; i < N; i++)
	{
		x2 = 1.0;
		do {
			x1 = x2;
			x2 = 0.5 * (x1 + n[i] / x1);
		} while (abs(sqrt(n[i]) - x2) > soglia);
		cout << "La radice del numero " << n[i] << " vale: " << x2 << endl;
	}
}

