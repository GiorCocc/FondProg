#include"es3_3_class.h"

using namespace std;

int main() {
	Pair<int> c1(1, 2);
	Pair<int> c2(4, 99);
	cout << "Coppia c1 1: " << c1.get_element(1) << " 2: " << c1.get_element(2) << endl;
	cout << "Coppia c2 1: " << c2.get_element(1) << " 2: " << c2.get_element(2) << endl;

	Pair<float> cf1;
	cf1.set_element(1, 3.253);
	cf1.set_element(2, 126.5);
	cout << "Coppia cf1 1: " << cf1.get_element(1) << " 2: " << cf1.get_element(2) << endl;

	c1.add_up(c2);
	cout << "Coppia c1 1: " << c1.get_element(1) << " 2: " << c1.get_element(2) << endl;

}