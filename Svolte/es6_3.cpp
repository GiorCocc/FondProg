#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h> // Used by timing functions

using namespace std;

#include "llist.h"
#include "link.h"
#include "listTest.h"

void insertionsort(LList<Item> &l)
{
	Item corrente, temp;
	int lLength = l.length();		  //salvo la dimensione della lista originale
	for (int i = 0; i < lLength; i++) //scorro la lista in lunghezza
	{
		l.moveToPos(i);				//mi posizione nella lista in i
		temp = l.getValue();		//salvo il valore puntato
		for (int j = 0; j < i; j++) //scorro la lista fino alla posizione i
		{
			l.moveToPos(j);					 //entro nella lista in j
			corrente = l.getValue();		 //salvo il valore puntato
			if (temp.key() < corrente.key()) //eseguo il confronto decrescente
			{
				l.moveToPos(i); //mi posiziono nella lista in indi i
				l.remove();		//rimuovo il valore
				l.moveToPos(j); //mi sposto nella posizione j
				l.insert(temp); //inserisco il valore
				break;
			}
		}
	}
}

int main()
{
	LList<Item> lista;
	srand(time(NULL));
	//int N = rand() % 30 + 1;
	int N = 10;
	int numero;

	//inizializzazione di una liste in modo casuale
	for (int i = 0; i < N; i++)
	{
		numero = rand() % 30;
		lista.insert(Item(numero)); //inserimento del valore nella lista
	}
	cout << "Lista: ";
	lprint(lista);
	cout << endl;

	insertionsort(lista);
	lista.moveToStart();
	cout << "Lista ordinata: ";
	lprint(lista);
	cout << endl;
}
