#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
#include <string>
using namespace std;

static int maxKey = 1000000;	//chiave massima per l'elenco dei telefoni
static string maxKeystr = "1000";	//chiave massima per l'elenco degli uffici
typedef string KeyA;	//chiave per gli uffici
typedef int KeyB;	//chiave per i telefoni

//classe per gli elementi dell'albero degli uffici
class ItemA
{
private:
	string ufficio;
	KeyA keyval;
public:
	ItemA(string u = "", KeyA k = maxKeystr){
		ufficio = u;
		keyval = k;
	}
	KeyA key() const { return keyval; }
	int null() { return keyval == maxKeystr; }
	void setufficio(string str) { ufficio = str; }
	string getufficio() const { return ufficio; }
	void show(ostream& os = cout) { os << ufficio << " " << keyval << endl; }
};

inline ostream& operator<<(ostream& os, const ItemA& x) {
	return os << x.getufficio() << " " << x.key() << endl;
}

//classe per gli elementi dell'albero dei numeri di telefono
class ItemB
{
private:
	string nome;
	KeyB keyval;
public:
	ItemB(string n = "", KeyB k = maxKey) {
		nome = n;
		keyval = k;
	}
	KeyB key() const { return keyval; }
	int null() { return keyval == maxKey; }
	void setnome(string str) { nome = str; }
	string getnome() const { return nome; }
	void show(ostream& os = cout) { os << keyval << " " << nome << endl; }
};

inline ostream& operator<<(ostream& os, const ItemB& x) {
	return os << x.key() << " " << x.getnome() << endl;
}

#endif