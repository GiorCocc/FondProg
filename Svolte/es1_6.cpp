#include<iostream>
#include<string>
#include<ctime>

using namespace std;

int main() {
	float prezzo, prezzoFinale=0;
	cout << "Prezzo articolo: ";
	cin >> prezzo;
	if (prezzo > 100)
		prezzo -= prezzo * 0.35;
	prezzoFinale = prezzo + prezzo * 0.22;
	cout << "Il prezzo finale e\': " << prezzoFinale;
}

