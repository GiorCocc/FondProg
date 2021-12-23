#ifndef ES1
#define ES1

#include<iostream>
#include<string>

using namespace std;

class Libro {
private:
	string titolo;
	int pagine;
public:
	Libro(string t = "", int p = 0) {
		titolo = t;
		pagine = p;
	}
	string getTitolo() {
		return titolo;
	}
	int getPagine() {
		return pagine;
	}
	void setTitolo(string t) {
		titolo = t;
	}
	void setPagine(int p) {
		pagine = p;
	}
};

#endif // !ES1