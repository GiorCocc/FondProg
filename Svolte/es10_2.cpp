#include<iostream>
#include<list>
#include<ctime>
#include"es10_2_listTest.h"
#include"link.h"
#include"llist.h"

using namespace std;

void inserimento(int n, list<Item>& lista) {
	int val;
	for (int i = 0; i < n; i++) {
		val = rand() % 30;
		Item temp(val);
		lista.push_back(temp);
	}
}

void stampaLista(list<Item>& lista) {
	if (lista.empty())
		cout << "Lista vuota";
	else {
		for (list<Item>::iterator i = lista.begin(); i != lista.end(); i++) {
			cout << *i << "\t";
		}
		cout << endl;
	}
}

int main() {
	LList<list<Item>> lista_di_liste;
	list<Item> l1, l2, l3;
	int n, m, l;

	srand(time(NULL));
	n = rand() % 10 + 1;
	m = rand() % 10 + 1;
	l = rand() % 10 + 1;

	inserimento(n, l1);
	cout << "l1:";
	stampaLista(l1);
	inserimento(m, l2);
	cout << "l2:";
	stampaLista(l2);
	inserimento(l, l3);
	cout << "l3:";
	stampaLista(l3);

	lista_di_liste.append(l1);
	lista_di_liste.append(l2);
	lista_di_liste.append(l3);

	lista_di_liste.moveToStart();
	int massimo = lista_di_liste.getValue().front().key();
	for (lista_di_liste.moveToStart(); lista_di_liste.currPos() < lista_di_liste.length(); lista_di_liste.next()) {
		list<Item> l = lista_di_liste.getValue();
		for (list<Item>::iterator i = l.begin(); i != l.end(); i++) {
			if ((*i).key() > massimo)
				massimo = (*i).key();
		}
	}
	cout << "Massimo: " << massimo << endl;


}