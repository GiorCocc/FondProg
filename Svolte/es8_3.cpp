#include <iostream>
#include <ctime>
#include "es8_3_heap.h"

using namespace std;
const int k = 3;
const int n = 4;

int main()
{
	int a[k][n] = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}}; //inizializzazione di una matrice
	MinHeap<Item> minheap(k);									//minheap di elementi interi
	int arrayOrdinato[k * n];
	int j = 0;

	for (int i = 0; i < k; i++)
	{
		Item temp(a[i][0], i, 1); //prendo il primo elemento dell'array
		minheap.insert(temp);	  //inserisco nel min-heap
	}

	for (int i = 0; i < k * n; i++)
	{
		Item temp = minheap.getMin();  //estraggo l'elemento più piccolo
		arrayOrdinato[j] = temp.key(); //inserisco nell'array il valore estratto

		if (temp.nextElement < n)
		{
			Item temp2(a[temp.id][temp.nextElement], temp.id, temp.nextElement + 1); //estraggo l'elemento successivo a quello precedentemente etratto
			minheap.insert(temp2);													 //inserisco nell'heap
		}
		j++;
	}

	cout << "Array ordinato: ";
	for (int i = 0; i < k * n; i++)
	{
		cout << arrayOrdinato[i] << " ";
	}
}