#include "es2_4_class.h"
#include<fstream>

int main() {
	Persona p1("antonio", "de franceschi", 33);
	Persona p2("giacomo", "salvatori", 29);

	cout << p1.getInformation() << endl;
	cout << p2.getInformation() << endl;

	ofstream output("es2_4_output.txt");

	if (p1 != p2)
	{
		output << "Diversi";
	}
	else output << "Uguali";
}