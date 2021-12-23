#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> // Used by timing functions

#include "lqueue.h"
#include "es5_5_LQueueTest.h"

using namespace std;

int main()
{
	LQueue<Item> queue1, queue2;
	srand(time(NULL));
	int N = rand() % 20 + 1;
	int M = rand() % 20 + 1;
	int num;

	//inizializzazione casuale della prima coda
	for (int i = 0; i <= N; i++)
	{
		num = rand() % 100 + 1;
		queue1.enqueue(Item(num));
	}
	cout << "Coda1: ";
	Lqueueprint(queue1);
	cout << endl;

	//inizializzazione casuale della seconda coda
	for (int i = 0; i <= M; i++)
	{
		num = rand() % 100 + 1;
		queue2.enqueue(Item(num));
	}
	cout << "Coda2: ";
	Lqueueprint(queue2);
	cout << endl;

	cout << "Le due code sono uguali? ";
	
	if (equal_queues(queue1, queue2) == 1) //controllo se le due code sono uguali
	{
		cout << "Si";
	}
	else
		cout << "No";
}