#include <iostream>
#include <ctime>
#include "es8_1_heap.h"

using namespace std;

int main()
{
	MinHeap<int> minheap(20);	//inizializzazione di un min-heap di valori interi
	int n;
	srand(time(NULL));

	//inizializzazione casuale degli elementi dell'heap
	for (int i = 0; i < 10; i++)
	{
		n = rand() % 100 + 1;
		minheap.insert(n);
	}
	//stampa degli elementi dell'heap
	for (int i = 0; i < 7; i++)
		cout << "Elemento piu\' piccolo: " << minheap.getMin() << endl;
}