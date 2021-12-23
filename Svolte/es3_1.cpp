#include"es3_1_class.h"
#include<ctime>

using namespace std;

int main() {
	srand(time(NULL));
	int a = rand();
	int b = rand();
	float c = rand();
	float d = rand();
	float e = rand();

	cout << "max(" << a << "," << b << ")=" << max2<int>(a, b) << endl;
	cout << "max(" << c << "," << d << "," << e << ")=" << max3<float>(c, d, e) << endl;
}