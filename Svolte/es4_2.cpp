#include <iostream>
#include <ctime>
#include "link.h"
#include "llist.h"
#include "es4_2_listTest.h"

using namespace std;

int find(List<Item> &L, const Item &K)
{
	Item it;
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
	{
		it = L.getValue();
		if (K.key() == it.key()) //controllo che le abbreviazioni concidano
			return L.currPos();	 // Found K
	}
	return -1; // K not found
}

int cercaAbbreviazione(LList<Item> &L, Item a)
{
	int pos = find(L, a); //ricerca nella lista per abbreviazioni
	if (pos == -1)
	{
		L.append(a);
		return 1; //non esiste un elemento che possiede la parola estesa
	}
	else
	{
		Item elemento;
		L.moveToPos(pos);						   //mi posiziono nella lista
		elemento = L.getValue();				   //salvo l'elemento
		if (elemento.getParola() != a.getParola()) //la parola dell'elemento a e quella contenuta nella lista non coincidono
		{
			L.remove();						   //rimuovo l'elemento
			elemento.setParola(a.getParola()); //imposto la parola corretta
			L.insert(elemento);				   //inserisco l'elemento nella stessa posizione
			return 2;						   //se l'abbreviazione è presente ma ad essa corrisponde una parola differente
		}
		else
			return 0; //esiste un elemento che possiede abbreviazione e parola estesa
	}
}

int main()
{
	LList<Item> L1;

	L1.append(Item("Mi", "Milano"));
	L1.append(Item("Ge", "Genova"));
	L1.append(Item("Kr", "Catanzaro"));
	L1.append(Item("Ve", "Venezia"));
	L1.append(Item("Pr", "Parma"));

	cout << "L1: ";
	lprint(L1);

	Item temp("Ve", "Venezia");
	int ris = cercaAbbreviazione(L1, temp);
	if (ris == 0)
		cout << "L'elemento esiste in modo completo" << endl;
	else if (ris == 1)
		cout << "L'elemento non esiste" << endl;
	else
		cout << "L'abbreviazione corrispondente all'elemento e\' presente ma corrisponde a una parola diversa" << endl;
	cout << "L1: ";
	lprint(L1);

	Item temp1("Pc", "Piacenza");
	ris = cercaAbbreviazione(L1, temp1);
	if (ris == 0)
		cout << "L'elemento esiste in modo completo" << endl;
	else if (ris == 1)
		cout << "L'elemento non esiste" << endl;
	else
		cout << "L'abbreviazione corrispondente all'elemento e\' presente ma corrisponde a una parola diversa" << endl;
	cout << "L1: ";
	lprint(L1);

	Item temp2("Kr", "Crotone");
	ris = cercaAbbreviazione(L1, temp2);
	if (ris == 0)
		cout << "L'elemento esiste in modo completo" << endl;
	else if (ris == 1)
		cout << "L'elemento non esiste" << endl;
	else
		cout << "L'abbreviazione corrispondente all'elemento e\' presente ma corrisponde a una parola diversa" << endl;
	cout << "L1: ";
	lprint(L1);
}