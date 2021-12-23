#ifndef ES1
#define ES1

#include<iostream>
#include<string>

using namespace std;

class Persona {
private:
	string nome;
	string cognome;
	int anni;
public:
	Persona(string n="", string c="", int a=0) {
		nome = n;
		cognome = c;
		anni = a;
	}
	string getInformation();
	void setCognome(string c);
};

#endif // !ES1