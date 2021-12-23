#ifndef ES1
#define ES1

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Money {
private:
	int euros;
	int cent;
public:
	Money(int e = 0, int c = 0) {
		euros = e;
		cent = c;
	}
	int getEuros() { return euros; }
	int getCent() { return cent; }
	void setEuros(int e) { euros = e; }
	void setCent(int c) { cent = c; }
};

class CreditCard {
private:
	string proprietario;
	string numero;
	Money totale;
public:
	CreditCard(string p = "", string n = "") {
		proprietario = p;
		numero = n;
	}
	void print();
	Money getTotale() { return totale; };
	void charge(string item, int e, int c);
};

//funzioni non-membro
Money operator+(Money m1, Money m2);	//converte gli euro in centesimi, fa la somma e riconverte
ostream& operator<<(ostream& os, Money m);	//stampa i dati membri

#endif // !ES1