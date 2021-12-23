#include"es3_0_class.h"

using namespace std;

int main() {
	Mobile m;
	m.setAltezza(3);
	m.setLarghezza(4);
	cout << "Altezza: " << m.getAltezza() << "\t" << "Larghezza: " << m.getLarghezza() << endl;

	Armadio a;
	a.setAltezza(3);
	a.setLarghezza(4);
	a.setNumeroAnte(4);
	cout << "Altezza: " << a.getAltezza() << "\t" << "Larghezza: " << a.getLarghezza() << "\t" << "Numero Ante: " << a.getNumeroAnte() << endl;
}