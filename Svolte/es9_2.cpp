#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

#include "es9_2_bst.h"
#include "es9_2_symbol_table_item.h"

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
	BST<ItemA, KeyA> uffici;
	BST<ItemB, KeyB> telefoni;
	string ufficio, nome_cognome, strtelefono, str;
	KeyB telefono;

	ifstream file("telefoni.txt");
	if (file.is_open())
	{
		//leggo gli elementi da file che sono separati da ,
		while (getline(file, ufficio, ',')) //inserimento in ufficio del primo valore letto
		{
			getline(file, nome_cognome, ','); //inserimento del nominativo del secondo valore letto
			getline(file, strtelefono);		  //inserimento del numero di telefono letto in una stringa

			//converto il numero di telefono da stringa a intero
			istringstream token(strtelefono);
			token >> telefono;

			ItemA tempA(ufficio, nome_cognome);	 //creazione dell'oggetto item per il primo albero
			ItemB tempB(nome_cognome, telefono); //creazione dell'oggetto item per il secondo albero

			//inserisco gli Item nei rispettivi alberi
			uffici.insert(tempA);
			telefoni.insert(tempB);
		}
	}
	file.close();

	//bilancio e stampo i due bst
	cout << "Uffici:" << endl;
	uffici.balance();
	uffici.show(cout);
	cout << endl;
	cout << "Telefoni:" << endl;
	telefoni.balance();
	telefoni.show(cout);
	cout << endl;

	//stampa su una riga l'ufficio, la chiave del primo albero (il nome) e la chiave del secondo albero (numero di telefono)
	for (int i = 0; i < telefoni.tree_size(); i++) //scorro tutta la lunghezza dell'albero
	{
		ItemB itemB = telefoni.select(i);			  //ritorno il primo elemento che incontro
		ItemA itemA = uffici.search(itemB.getnome()); //ricerco nel secondo albero l'elemento preso per nome

		cout << itemA.getufficio() << " " << itemA.key() << " " << itemB.key() << endl; //stampa
	}

	while (true)
	{
		cout << endl
			 << "Insercisci una stringa: ";
		getline(cin, str);

		//se la stringa è un numero, cerco nell'albero dei numeri di telefono tale elemento
		if (isNumber(str))
		{
			istringstream token(str); //converto il numero da stringa a intero
			token >> telefono;

			ItemB itemB = telefoni.search(telefono);
			ItemA itemA = uffici.search(itemB.getnome()); //ricerca dell'elemento

			if (itemB.null()) //ricerca con esito negativo
				cout << "Elemento non trovato" << endl;
			cout << itemA.getufficio() << " " << itemA.key() << " " << itemB.key() << endl; //stampa dei dati
		}
		//se il valore inserito non è un numero, cerco tutte le persone in un ufficio
		else
		{
			cout << "Elenco persone nello stesso ufficio di " << str << " :";
			ItemA itemA = uffici.search(str);				 //ricerca nell'albero degli elementi che hanno quella chiave
			if (!itemA.null())								 //ricerca avvenuta con successo
				for (int i = 0; i < uffici.tree_size(); i++) //scorro l'albero degli uffici
				{
					ItemA ita = uffici.select(i);				//seleziono un elemento
					if (ita.getufficio() == itemA.getufficio()) //se gli uffici coincidono stampo
						cout << ita.key() << endl;				//stampa della chiave
				}
		}
	}
}