#include <iostream>
#include <ctime>
#include "link.h"
#include "llist.h"
#include "listTest.h"

using namespace std;

void insert_ordered(List<Item> &L, const Item &it)
{
	if (L.length() == 0)
	{
		L.insert(it);
		return;
	}
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
	{
		if (it.key() >= L.getValue().key())
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}

void fondiListe(List<Item> &L1, List<Item> &L2, List<Item> &L3)
{
	Item temp;
	//inserisco tutti gli elementi della lista L1
	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next())
	{
		temp = L1.getValue();
		insert_ordered(L3, temp); //inserimento ordinato nella lista L3
	}
	//inserisco tutti gli elementi di L2
	for (L2.moveToStart(); L2.currPos() < L2.length(); L2.next())
	{
		temp = L2.getValue();
		insert_ordered(L3, temp); //inserimento ordinato nella lista L3
	}
}

int main()
{
	LList<Item> L1;
	LList<Item> L2;
	LList<Item> L3;
	srand(time(NULL));

	for (int i = 0; i < rand() % 20; i++)
	{
		L1.append(rand() % 20 + 1);
		L2.append(rand() % 20 + 1);
	}

	cout << "L1: ";
	lprint(L1);
	cout << "L2: ";
	lprint(L2);

	fondiListe(L1, L2, L3);
	cout << "Lista fusa L3: ";
	lprint(L3);
}