#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> // Used by timing functions

#include "lstack.h"
#include "LStackTest.h"

using namespace std;

int main()
{
	LStack<Item> stack;
	Item Itemp;
	srand(time(NULL));
	int N = rand() % 15 + 1; //numero casuale di elementi
	int fattoriale = 1;		 //fattoriale di 0
	int temp;

	for (int i = 1; i <= N; i++)
	{
		Item temp(i);	  //creo oggetti item da 1 a N
		stack.push(temp); //inserisco nello stack
	}

	cout << "Stack: ";
	Lstackprint(stack); //stampo lo stack
	cout << endl;

	//ciclo per il calcolo del fattoriale
	for (int i = 1; i <= N; i++)
	{
		Itemp = stack.pop(); //rimuovo un elemento dallo stack
		temp = Itemp.key();	 //estraggo il dato in esso contenuto
		fattoriale *= temp;	 //calcolo il fattoriale
	}

	cout << "Fattoriale di " << N << ": " << fattoriale << endl;
}