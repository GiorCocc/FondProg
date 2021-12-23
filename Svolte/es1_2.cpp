/*Scrivere un programma che crei due vettori di numeri interi a e b di lunghezza N=5. 
Il vettore b va inizializzato generando nel codice la sequenza di numeri 0, ‐3, 6, ‐9, 12. 
Il vettore a va creato con dei numeri a scelta. 
Il programma deve calcolare la somma incrociata degli elementi: a[0]+b[N-1], a[1]+b[N-2], …, a[N-1]+b[0] e memorizzarla nel vettore c. 
Il programma deve inoltre creare un vettore d della stessa lunghezza con valore 1 se a[i] > b[i], 0 se a[i]=b[i] e ‐1 altrimenti. 
Si visualizzino i contenuti di a, b, c, d.
*/


#include<iostream>
#include<math.h>
const int N = 31;

using namespace std;

void stampa(int v[N]) {
	for (int i = 0; i < N; i++)
		cout << v[i] << "\t";
	cout << endl;
}

int main() {
	int c1[N], c2[N];
	int giorno;
	for (int i = 0; i < N; i++)
	{
		c1[i] = c2[i] = 0;
	}
	cout << "Collega 1";
	do {
		cout << "Inserisci il giorno (1-31) in cui sei disponibile (0 per terminare): ";
		cin >> giorno;
		if (giorno > 0 && giorno < 31)
			c1[giorno - 1] = 1;
	} while (giorno != 0);
	cout << "Collega 2";
	do {
		cout << "Inserisci il giorno (1-31) in cui sei disponibile (0 per terminare): ";
		cin >> giorno;
		if (giorno > 0 && giorno < 31)
			c2[giorno - 1] = 1;
	} while (giorno != 0);

	cout << "La riunione puo\' essere fissata nei giorni: " << endl;
	for (int i = 0; i < N; i++)
	{
		if (c1[i] == 1 && c2[i]==1)
			cout << i+1 << "\t";
	}
}

