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
	Item Itemp1, Itemp2;
	srand(time(NULL));
	int N = rand() % 20 + 1;
	//int N = 10;

	stack.push(1); //inserisco nello stack il primo elemento della sequenza
	stack.push(1); //inserisco nello stack il secondo elemento della sequenza
	//cout << "Stack: "; Lstackprint(stack); cout << endl;

	for (int i = 1; i <= (N - 2); i++)
	{
		Itemp1 = stack.pop(); //estraggo un elemento dalla sequenza
		//cout << Itemp1.key() << endl;
		Itemp2 = stack.pop(); //estraggo un elemento dalla sequenza
		//cout << Itemp2.key() << endl;

		Item Itemp3(Itemp1.key() + Itemp2.key()); //creo un oggetto item che contiene la somma dei due elementi estratti
		//cout << Itemp3.key() << endl;

		stack.push(Itemp2); //inserisco il secondo valore estratto
		stack.push(Itemp1); //inserisco il primo valore estratto
		stack.push(Itemp3); //inserisco l'elemento della sequenza appena calcolato

		//cout << "Stack: "; Lstackprint(stack); cout << endl;
	}

	//cout << endl;
	cout << "Fibonacci: ";
	Lstackprint(stack); //stampo lo stack
	cout << endl;
}