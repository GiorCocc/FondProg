#include <iostream>
#include <ctime>
#include "link.h"
#include "llist.h"
#include "listTest.h"

const int N = 3;
using namespace std;

int main()
{
	LList<Item> array_liste[N]; //array di liste
	srand(time(NULL));

	//creazione e stampa dell'array di liste
	for (int i = 0; i < N; i++) //ciclo per stampare le singole liste
	{
		for (int j = 0; j < rand() % 10 + 1; j++) //ciclo per l'inizializzazione di un numero casuale di liste
			array_liste[i].append(rand() % 500);  //inserisco in ogni lista un elemento casuale
		cout << "array_liste[" << i << "]:";
		lprint(array_liste[i]); //stampa della singola lista
	}

	int max = 0;		//massimo
	int lista_max = 0;	//indice della lista che contiene il massimo
	int indice_max = 0; //indice massimo dell'elemento
	int cont = 0;		//indice elemento
	Item temp;

	for (int i = 0; i < N; i++) //scorro le singole liste
	{
		cont = 0;
		for (array_liste[i].moveToStart(); array_liste[i].currPos() < array_liste[i].length(); array_liste[i].next())
		{
			temp = array_liste[i].getValue(); //prelevo un elemento dalla lista
			if (temp.key() > max)			  //controllo che il valore sia massimo
			{
				max = temp.key();  //salvo il nuovo massimo
				lista_max = i;	   //salvo la lista in cui è contenuto
				indice_max = cont; //calvo l'indice in cui si trova l'elemento massimo
			}
			++cont;
		}
	}

	cout << "L'elemento dal valore massimo e\': " << max << " e si trova nella lista " << lista_max << " in posizione " << indice_max + 1 << endl;
}