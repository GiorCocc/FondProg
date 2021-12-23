#include<iostream>
#include<list>
#include<queue>
#include<ctime>

using namespace std;

int main() {
	list<queue<int>> lista_di_code;
	queue<int> q1, q2, q3, q4;
	int n, m, l;

	q1.push(30); q1.push(12); q1.push(1); q1.push(203); q1.push(10);
	q2.push(7);
	q3.push(14); q3.push(29); q3.push(45); q3.push(100);
	q4.push(2); q4.push(13); q4.push(8);

	lista_di_code.push_back(q1);
	lista_di_code.push_back(q2);
	lista_di_code.push_back(q3);

	list<queue<int>>::iterator ultimo = lista_di_code.end();
	list<queue<int>>::iterator penultimo = --ultimo;
	list<queue<int>>::iterator successivo;
	list<queue<int>>::iterator i;
	for (i = lista_di_code.begin(); i != penultimo; i++) {
		if ((*i).size() > 0) {
			int val = (*i).front();
			(*i).pop();
			successivo = i;
			++successivo;
			(*successivo).push(val);
		}
	}

	for (i = lista_di_code.begin(); i != lista_di_code.end(); i++) {
		while (!(*i).empty()) {
			cout << (*i).front() << "\t";
			(*i).pop();
		}
		cout << endl;
	}
}