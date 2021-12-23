#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

#include "es9_3_bst.h"
#include "es9_3_symbol_table_item.h"

using namespace std;

//funzione per il controllo che la stringa inserita rappresenti un numero
bool isNumber(string s)
{
	if (s.size() == 0)
		return false;
	for (int i = 0; i < s.size(); i++)
	{
		//controllo che il carattere inserito sia un carattere compreso tra 0 e 9
		if (s[i] >= '0' && s[i] <= '9')
			return true;
		else
			return false;
	}
}

int main()
{
	BST<Item, Key> parteA, parteB;
	string nome, voto_str, email, matricola_str;
	int voto, matricola;

	ifstream fileA("parteA.txt");
	if (fileA.is_open())
	{
		/*cout << "File a aperto";*/
		while (getline(fileA, matricola_str, ',')) //salvo la matricola come stringa
		{
			getline(fileA, nome, ',');	   //salvo il nome
			getline(fileA, voto_str, ','); //salvo il voto come stringa
			getline(fileA, email);		   //salvo la mail

			//converto la chiave matricola in intero
			istringstream chiave(matricola_str);
			chiave >> matricola;

			if (!isNumber(voto_str))
				voto = 0; //se nel campo voto non ho un numero (INSUFFICIENTE), il voto è 0
			else
			{
				istringstream votoStringToInt(voto_str); //converto il voto in intero
				votoStringToInt >> voto;				 //inserisco il valore convertito in una variabile intera
			}

			Item data(nome, voto, email, matricola); //creo l'oggetto item
			parteA.insert(data);					 //inserisco nell'albero relativo alla prima parte
		}
	}
	fileA.close();

	ifstream fileB("parteB.txt");
	if (fileB.is_open())
	{
		while (getline(fileB, matricola_str, ',')) //salvo la matricola come stringa
		{
			getline(fileB, nome, ',');	   //salvo il nome
			getline(fileB, voto_str, ','); //salvo il voto come stringa
			getline(fileB, email);		   //salvo la mail

			//converto la chiave matricola in intero
			istringstream chiave(matricola_str);
			chiave >> matricola;

			if (!isNumber(voto_str))
				voto = 0; //se nel campo voto non ho un numero (INSUFFICIENTE), imposto il voto a 0
			else
			{
				istringstream votoStringToInt(voto_str); //converto il voto in intero
				votoStringToInt >> voto;				 //inserisco il voto in una variabile intera
			}

			Item data(nome, voto, email, matricola); //creo l'oggetto item
			parteB.insert(data);					 //inserisco l'oggetto item nel secondo albero
		}
	}
	fileB.close();

	cout << "Parte A: " << endl;
	parteA.balance();
	parteA.show(cout);
	cout << endl;
	cout << "Parte B: " << endl;
	parteB.balance();
	parteB.show(cout);
	cout << endl;

	//stampa la media dei voti
	parteA.stampaRisultati(parteB);
}