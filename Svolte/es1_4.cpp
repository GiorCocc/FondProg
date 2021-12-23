#include<iostream>
#include<string>
#include<ctime>
const int N = 3;
const int MAX = 201;

using namespace std;

struct tipoLibro {
	string titolo, autore;
	int anno;
	float prezzo;
};

int main() {
	tipoLibro libri[N];
	float prezzoTotale = 0.0;
	float prezzoMassimo = 0.0;
	int idPrezzo=-1, idAnno=-1, annoMinimo;
	annoMinimo = 10000000000;

	srand(time(NULL));


	for (int i = 0; i < N; i++)
	{
		cout << "Inserire i dati del libro " << i << " [titolo autore anno]: ";
		cin >> libri[i].titolo >> libri[i].autore >> libri[i].anno;
		libri[i].prezzo = rand() % MAX;
		cout << "Prezzo generato casualmente: " << libri[i].prezzo << endl;

		prezzoTotale += libri[i].prezzo;

		if (libri[i].prezzo > prezzoMassimo) {
			prezzoMassimo = libri[i].prezzo;
			idPrezzo = i;
		}
		if (libri[i].anno < annoMinimo) {
			annoMinimo = libri[i].anno;
			idAnno = i;
		}
	}

	cout << "La media del costo dei libri e\': " << prezzoTotale / N << endl;
	cout << "Il libro con il prezzo piu\' alto, pari a " << prezzoMassimo << " ,e\': " << libri[idPrezzo].titolo << endl;
	cout << "Il libro piu\' vecchio, del " << annoMinimo << " ,e\': " << libri[idAnno].titolo << endl;
}

