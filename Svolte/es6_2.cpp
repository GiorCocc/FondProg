#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h> // Used by timing functions

using namespace std;

#include "alist.h"
#include "es6_2_listTest.h"

int mindata(Item uno, Item due)
{
	if ((uno.getAnno() < due.getAnno()) ||
		((uno.getAnno() == due.getAnno()) && (uno.getMese() < due.getMese())) ||
		((uno.getAnno() == due.getAnno()) && (uno.getMese() == due.getMese()) && (uno.getGiorno() < due.getGiorno()))) //ordinamento per data
		return 1;
	else
		return 0;
}

void selectionsort(List<Item> &L)
{
	int min_pos;
	Item min_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i < L.length() - 1; i++)
	{
		L.moveToPos(i);
		min_element = L.getValue();
		min_pos = i;
		for (int j = i + 1; j < L.length(); j++)
		{
			L.moveToPos(j);
			Item it_temp = L.getValue();
			if (
				(it_temp.getCognome() < min_element.getCognome()) ||
				((it_temp.getCognome() == min_element.getCognome()) && (it_temp.getNome() < min_element.getNome())) ||
				((it_temp.getCognome() == min_element.getCognome()) && (it_temp.getNome() == min_element.getNome()) && (mindata(it_temp, min_element)))) //ordinamento per cognome, nome e data
			{
				min_pos = L.currPos();
				min_element = it_temp;
			}
		}
		L.moveToPos(min_pos);
		Item it_temp = L.remove();
		L.moveToPos(i);
		L.insert(it_temp);
	}
}

int main()
{
	AList<Item> agenda(100); //fisso la dimensione massima a 100
	string nome, cognome;
	int giorno, mese, anno;
	string stringa, temp;

	ifstream file("agenda.txt"); //leggo da file
	if (file.is_open())
	{
		//cout << "File aperto";
		while (file >> nome >> cognome >> stringa)
		{
			temp = stringa.substr(0, 2);
			istringstream converto(temp); //converto la sottostringa per ricavare il giorno
			converto >> giorno;

			temp = stringa.substr(3, 2);
			istringstream converto1(temp);
			converto1 >> mese; //converto la sottostringa per ricavare il mese

			temp = stringa.substr(6, 4);
			istringstream converto2(temp);
			converto2 >> anno; //converto la sottostringa per ricavare l'anno

			Item record(nome, cognome, giorno, mese, anno); //creo l'oggetto item
			//cout << record << endl;
			agenda.insert(record); //inserisco in agenda
		}
		file.close();
	}
	else
		cout << "Errore!";

	cout << "Agenda: ";
	lprint(agenda);
	cout << endl;

	selectionsort(agenda);
	agenda.moveToStart();
	cout << "Agenda ordinata: ";
	lprint(agenda);
	cout << endl;
}