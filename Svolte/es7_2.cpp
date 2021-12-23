#include <iostream>
#include <ctime>
#include "es7_2_binary_tree.h"

using namespace std;

int main()
{
	BinaryTree<Item> *alberoA = new BinaryTree<Item>;
	BinaryTree<Item> *alberoB = new BinaryTree<Item>;
	int risultato;
	srand(time(NULL));

	//inizializzazione casuale di due alberi
	for (int i = 0; i < 8; i++)
	{
		int valA = rand() % 20;
		Item vA(valA);
		alberoA->AddItem(vA);

		int valB = rand() % 20;
		Item vB(valB);
		alberoB->AddItem(vB);
	}

	cout << "Post order A: ";
	alberoA->traverse();
	cout << "Post order B: ";
	alberoB->traverse();
	cout << endl;

	risultato = alberoA->equal_tree_structure(alberoB->root); //controllo se due alberi hanno la stessa struttura
	if (risultato == 1)
		cout << "Gli alberi hanno la stessa struttura" << endl;
	else
		cout << "Gli alberi hanno una struttura diversa" << endl;
}