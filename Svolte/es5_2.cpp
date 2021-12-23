#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> // Used by timing functions

#include "es5_2_lqueue.h"
#include "LQueueTest.h"

using namespace std;

int main()
{
	LQueue<Item> queue;
	srand(time(NULL));
	int N = rand() % 20 + 1;
	int num;

	//inizializzazione casuale della coda
	for (int i = 0; i <= N; i++)
	{
		num = rand() % 100 + 1;
		queue.enqueue(Item(num));
	}

	cout << "Queue: ";
	Lqueueprint(queue);
	cout << endl;

	queue.reverse();
	cout << "Reversed Queue: ";
	Lqueueprint(queue);
	cout << endl;
}