#include <iostream>
#include <fstream>
#include <sstream>
#include "llist.h"
#include "link.h"
#include "es6_4_listTest.h"
#include "bubble.h"
#include "es6_4_comp.h"

using namespace std;

int main()
{
	int N, num_scelti, eta_max;
	Item *arrayStudenti = NULL;
	studente strutturaStudente;
	LList<Item> listaStudenti;

	cout << "Numero studenti: ";
	cin >> num_scelti;
	cout << "Eta\' massima: ";
	cin >> eta_max;

	ifstream file("studenti.txt");
	if (file.is_open())
	{
		file >> N;
		arrayStudenti = new Item[N]; //allocazione dinamica dell'array
		for (int i = 0; i < N; i++)
		{
			file >> strutturaStudente.cognome >> strutturaStudente.eta >> strutturaStudente.media;
			Item riga(strutturaStudente);
			arrayStudenti[i] = riga;
		}
		file.close();
	}
	else
	{
		cout << "Errore apertura file!";
		exit(-1);
	}

	//stampa dell'array
	cout << "ArrayStudenti: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arrayStudenti[i] << endl;
	}

	bubble<Item>(arrayStudenti, 0, N - 1); //ordinamento dell'array
	cout << "Array studenti ordinato per media voti: " << endl;
	//stampa dell'array ordinato
	for (int i = 0; i < N; i++)
	{
		cout << arrayStudenti[i] << endl;
	}

	for (int i = 0; i < N; i++) //scelgo il numero di studenti impostato da input
	{
		if (arrayStudenti[i].key().eta < eta_max) //controllo le loro età rispetto a quella massima impostata
		{
			listaStudenti.insert(arrayStudenti[i]);	  //inserisco nella lista
			if (listaStudenti.length() == num_scelti) //controllo che la lunghezza della lista sia uguale al al numero di quelli scelti
				break;
		}
	}

	cout << "Lista studenti scelti: ";
	lprint(listaStudenti); //stampa della lista
	cout << endl;
}