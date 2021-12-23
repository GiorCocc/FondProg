#include "es2_2_class.h"

int main() {
	Persona p[3];
	Persona p1("antonio", "de franceschi", 33);
	Persona p2("giacomo", "salvatori", 29);
	Persona p3("alessandro", "arcaini", 20);

	cout << p1.getInformation() << endl;
	cout << p2.getInformation() << endl;
	cout << p3.getInformation() << endl;

	p[0] = p1;
	p[1] = p2;
	p[2] = p3;

	for (int i = 0; i < 3; i++) {
		p[i].setCognome("bianchi");
		cout << p[i].getInformation() << endl;
	}

}