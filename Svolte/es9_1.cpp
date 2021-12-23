#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

#include "es9_1_bst.h"
#include "es9_1_symbol_table_item.h"

using namespace std;

int main()
{
	BST<Item, Key> bst1, bst2;
	LList<Item> llist;
	int key;
	string str;

	//salvo le informazione lette dal file e le inserisco in un bst
	ifstream file("info.dat");
	if (file.is_open())
	{
		cout << "File aperto";
		while (file >> key >> str)
		{
			Item temp(str, key); //creo oggetto Item da inserire
			bst1.insert(temp);	 //inserisco nel primo albero
		}
	}
	file.close();

	//lettura da tastiera di nuove elementi
	cout << "Inserire nuovi ID-stringa (valore negativo per chiudere)" << endl;
	do
	{
		cin >> key >> str;	//lettura di coppie id-stringa
		Item v(str, key);	//creazione di un item per l'inserimento
		if (v.key() >= 0)	//controllo che la chiave inserita sia positiva
			bst2.insert(v); //inserisco l'elemento in un secondo bst
	} while (key >= 0);		//terminazione quando il valore inserito come chiave è negativo

	cout << "BST1: " << endl;
	bst1.show(cout); //stampa dell'albero
	cout << endl;
	cout << "BST1 bilanciato:" << endl;
	bst1.balance();
	bst1.show(cout); //stampa dell'albero bilanciato
	cout << endl;
	cout << "BST2: " << endl;
	bst2.show(cout); //stampa del secondo albero
	cout << endl;
	cout << "BST2 bilanciato:" << endl;
	bst2.balance();
	bst2.show(cout); //stampa del secondo albero bilanciato
	cout << endl;

	//inserisco gli elementi presenti nei due alberi bilanciati in una LList
	bst1.merge(bst2, llist);
	cout << "Lista: ";
	lprint(llist);
	cout << endl;
}