#ifndef ES1
#define ES1

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Mobile {
private:
	int larghezza;
	int altezza;
public:
	Mobile(int l = 0, int a = 0) {
		larghezza = l;
		altezza = a;
	}
	void setAltezza(int a) { altezza = a; }
	void setLarghezza(int l) { larghezza = l; }
	int getAltezza() { return altezza; }
	int getLarghezza() { return larghezza; }
};

class Armadio : public Mobile {
private:
	int numero_ante;
public:
	Armadio(int n_a = 0) { numero_ante = n_a; }
	void setNumeroAnte(int n_a) { numero_ante = n_a; }
	int getNumeroAnte() { return numero_ante; }
};

#endif // !ES1