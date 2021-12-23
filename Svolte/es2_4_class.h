#ifndef ES1
#define ES1

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Persona {
private:
	string nome;
	string cognome;
	int anni;
public:
	Persona(string n = "", string c = "", int a = 0) {
		nome = n;
		cognome = c;
		anni = a;
	}
	bool operator!=(Persona p2) {
		if ((nome != p2.nome) || (cognome != p2.cognome) || (anni != p2.anni))
			return 1;
		else return 0;
	}
	string getInformation();
	void setCognome(string c);
};

#endif // !ES1