#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> // Used by timing functions
#include "lqueue.h"
#include "es5_6_LQueueTest.h"

using namespace std;

int main()
{
	LQueue<Item> queue;
	Item valore1, valore2;
	int N, step = 0;
	float num;

	cout << "Quanti valori? ";
	cin >> N;

	for (int i = 1; i <= N; i++) //inserimento manuale degli elementi nella coda
	{
		cout << "Dammi il #" << i << " numero: ";
		cin >> num;
		queue.enqueue(Item(num));
	}
	cout << "Coda: ";
	Lqueueprint(queue);
	cout << endl;

	while (queue.length() > 1)
	{
		int queueLength = queue.length();
		for (int i = 0; i < queueLength / 2; i++)
		{
			valore1 = queue.dequeue(); //estraggo un elemento
			valore2 = queue.dequeue(); //estraggo un elemento
			float ris;

			switch (step % 4) //eseguo sul numero di passi
			{
			case (0):
				ris = valore1.key() + valore2.key(); //eseguo la somma degli elementi vicini
				break;
			case (1):
				ris = valore1.key() - valore2.key(); //eseguo la sottrazione degli elementi vicini
				break;
			case (2):
				ris = valore1.key() * valore2.key(); //eseguo la moltiplicazione degli elementi vicini
				break;
			case (3):
				ris = valore1.key() / valore2.key(); //eseguo la divisione degli elementi vicini
				break;
			}

			Item valore3(ris);		//creo un oggetto contenente il risultato
			queue.enqueue(valore3); //inserisco il risultato nella coda
		}

		if (queue.length() % 2 == 1)
		{
			valore1 = queue.dequeue();
			queue.enqueue(valore1);
		}

		cout << "Queue: ";
		Lqueueprint(queue);
		cout << endl;
		step++; //aggiorno il numero di passi effettuati per cambiare operazione
	}
}