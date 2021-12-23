#include "es2_3_class.h"

void CreditCard::print() {
	cout << "Proprietario: " << proprietario << " numero: " << numero << endl;
}

void CreditCard::charge(string item, int e, int c) {
	Money transazione(e, c);
	cout << "Trasazione per: " << item << " di euro: " << e << "," << c << endl;
	totale = totale + transazione;
}

Money operator+(Money m1, Money m2) {
	int e = m1.getEuros() + m2.getEuros();
	int c = m1.getCent() + m2.getCent();

	e += c / 100;
	c %= 100;

	Money res(e, c);
	return res;
}

ostream& operator<<(ostream& os, Money m) {
	os << m.getEuros() << "." << m.getCent() << " euro";
	return os;
}