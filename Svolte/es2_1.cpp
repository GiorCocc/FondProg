#include "es2_1_class.h"

int main() {
	Libro libro1;
	Libro libro2("pippo", 300);
	cout << "Titolo: " << libro1.getTitolo() << "\tNumero pagine: " << libro1.getPagine() << endl;
	cout << "Titolo: " << libro2.getTitolo() << "\tNumero pagine: " << libro2.getPagine() << endl;

	libro1.setTitolo("alberto");
	libro1.setPagine(100);
	cout << "Titolo: " << libro1.getTitolo() << "\tNumero pagine: " << libro1.getPagine() << endl;
}