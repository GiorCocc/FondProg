#include "es2_4_class.h"

string Persona::getInformation() {
	string info;
	info = nome.substr(0, 1) + ". " + cognome + ", " + std::to_string(anni);
	return info;
}

void Persona::setCognome(string c) {
	cognome = c;
}