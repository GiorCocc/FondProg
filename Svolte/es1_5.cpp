#include<iostream>
#include<string>
#include<ctime>
const float pi = 3.141592653;

using namespace std;

void areaCerchio(float r, float& a) {
	a = pi * (r * r);
}

int main() {
	float raggio, area = 0;
	cout << "Dammi un raggio: ";
	cin >> raggio;
	areaCerchio(raggio, area);
	cout << "Area = "<< area << endl;
}

