#include <iostream>
#include <ctime>
#include "es7_4_binary_tree.h"

using namespace std;

int main()
{
	BinaryTree<Item> alberoA;
	int risultato;
	srand(time(NULL));

	//inizializzazione di un albero casuale
	for (int i = 0; i < 8; i++)
	{
		int valA = rand() % 20;
		Item vA(valA);
		alberoA.AddItem(vA);
	}

	cout << "Post order A: ";
	alberoA.traverse();
	cout << endl;
}