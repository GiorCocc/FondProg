#ifndef ES3
#define ES3

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

//file Header che contiene le definizioni delle classi e dei prototipi degli operatori

class Money {
private:
	int euros;
	int cents;
public:
	Money(int e = 0, int c = 0) { euros = e; cents = c; };
	int get_euros() { return euros; }; //definisco i metodi get e set nel file header, a rigore avrei dovuto definire anche loro nel cpp
	void set_euros(int e) { euros = e; };
	int get_cents() { return cents; };
	void set_cents(int c) { cents = c; };
};

//prototipo dell'operatore << sulla classe Money
//viene definito nel file cpp
ostream& operator<<(ostream& os, Money m);

class CreditCard {
private:
	string owner_name;
	string number;
	Money totalcharges;

public:
	CreditCard(string o, string n) { owner_name = o; number = n;};
	void charge(string item, int euros, int centimes);
	Money get_totalcharges() { return totalcharges; };
	void print();
};

//prototipo dell'operatore + per sommare due oggetti della classe Money
//viene definito nel cpp
Money operator+(Money m1, Money m2);

#endif