#include "es2_3_class.h"

int main() {
	CreditCard cc("Giorgio Coccapani", "123456789");
	string causale;
	int euro;
	int centesimi;
	cc.print();

	ifstream file("es2_3_transazioni.txt");
	if (file.is_open())
	{
		while (file >> causale >> euro >> centesimi) {
			cc.charge(causale, euro, centesimi);
		}
		cout << "Totale spese: " << cc.getTotale() << endl;
		file.close();

	} else
		cout << "Errore nell'apertura del file!" << endl;
}