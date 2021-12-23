#include <iostream>
#include <ctime>
#include "link.h"
#include "llist.h"
#include "listTest.h"

using namespace std;

void product(LList<Item> &L)
{
	Item corrente;
	Item precedente;

	for (L.moveToPos(L.length() - 1); L.currPos() > 0; L.prev()) //ciclo all'indietro
	{
		L.prev();										   //retrocedo
		precedente = L.getValue();						   //salvo l'elemento precedente
		L.next();										   //avanzo
		corrente = L.getValue();						   //salvo l'elemento corrente
		L.remove();										   //rimuovo l'elemento corrente
		L.insert(Item(precedente.key() * corrente.key())); //inserisco nella posizione corrente il prodotto dei due elementi
	}
}

int main()
{
	LList<Item> L;
	srand(time(NULL));

	//inizializzazione della lista
	for (int i = 0; i < rand() % 100 + 1; i++)
	{
		L.append(rand() % 20 + 1);
	}

	cout << "Lista di partenza: ";
	lprint(L);
	cout << endl;

	product(L);
	cout << "Lista di prodotti: ";
	lprint(L);
	cout << endl;
}