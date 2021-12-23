#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> // Used by timing functions

using namespace std;

#include "link.h"
#include "llist.h"
#include "listTest.h"

const int MINVAL = 0;
const int MAXVAL = 100;
const int N = 10;

void bubblesort(List<Item> &L)
{
	for (int i = 0; i < (L.length() - 1); i++)
	{
		for (int j = (L.length() - 1); j > i; j--)
		{
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key() > it_j.key())	//ordinamento crescente
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	LList<Item> L1, L2;
	Item temp;
	int randNum;

	//inizializzazione di due liste di uguale dimensione in modo casuale
	for (int i = 0; i < N; i++)
	{
		randNum = rand() % (MAXVAL - MINVAL + 1) + MINVAL;
		L1.insert(Item(randNum));
		randNum = rand() % (MAXVAL - MINVAL + 1) + MINVAL;
		L2.insert(Item(randNum));
	}

	cout << "L1: ";
	lprint(L1);
	cout << "L2: ";
	lprint(L2);

	//inserimento di L2 in L1
	L1.moveToStart();			//posiziono il cursore a linizio lista
	int L2length = L2.length(); //salvo la lunghezza della lista L2
	for (int i = 0; i < L2length; i++)
	{
		temp = L2.remove(); //rimuovo un elemento dalla lista L2
		L1.insert(temp);	//inserisco l'elemento rimosso in L1
	}
	cout << "L1+L2: ";
	lprint(L1);

	bubblesort(L1);	//ordinamento della lista L1
	L1.moveToStart();
	cout << "L1+L2 ordinato: ";
	lprint(L1);
}