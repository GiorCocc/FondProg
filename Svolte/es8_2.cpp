#include <iostream>
#include <ctime>
#include "es8_2_heap.h"

using namespace std;
const int N = 4;

int main()
{
	MinHeap<int> minheap(10);
	int len[N] = {4, 3, 2, 6}; //array con le dimensioni delle funi
	int costo = 0;

	//inserimento delle lunghezze nell'heap
	for (int i = 0; i < N; i++)
		minheap.insert(len[i]);

	for (int i = 0; i < N - 1; i++)
	{
		int primo = minheap.getMin();	//primo minimo
		int secondo = minheap.getMin(); //secondo minimo

		//cout << primo << "\t" << secondo;
		costo = costo + primo + secondo; //costo dei due valori
		//cout << "Costo:" << costo << endl;

		minheap.insert(primo + secondo); //inserimento del costo nell'heap
	}
	cout << "Costo totale: " << costo << endl;
}