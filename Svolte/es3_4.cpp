#include"es3_4_class.h"

using namespace std;

int main() {
	Matrix2x2<int> m1(0, 1, 2, 3);
	Matrix2x2<int> m2(12, 13, 17, 28);
	Matrix2x2<int> m3 = m1.Add(m2);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cout << m3.m[i][j] << "\t";
		cout << endl;
	}

}