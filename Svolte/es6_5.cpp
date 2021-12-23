#include <iostream>
#include <string>

using namespace std;

string reverse(string f)
{
	string rev = ""; //creazione della stringa inversa
	if (f.length() == 1)
		return f; //se la stringa è lunga 1 carattere, non c'è nulla da invertire
	else
	{
		rev += f[f.length() - 1] + reverse(f.substr(0, f.length() - 1)); //concatenazione di stringhe: carattere della stringa f alla fine e la ricorsione sulla sottostringa da 0 a lunghezza-1
		return rev;
	}
}

int main()
{
	string frase = "ciao a tutti come va";
	string frase_reverse;

	frase_reverse = reverse(frase);
	cout << "Frase: " << frase << endl;
	cout << "Frase riflessa: " << frase_reverse << endl;
}