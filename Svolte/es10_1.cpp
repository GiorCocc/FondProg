#include<iostream>
#include<list>

using namespace std;

int main() {
	list<int> lista;
	list<int>::iterator i;

	lista.push_back(1);
	lista.push_back(22);
	lista.push_back(4);
	lista.push_back(31);
	lista.push_back(4);
	lista.push_back(13);

	cout << "Lista: ";
	for (i = lista.begin(); i != lista.end(); i++) {
		cout << (*i) << "\t";
	}
	cout << endl;

	i = lista.begin();
	lista.insert(++i, 5);
	lista.insert(i, 15);

	cout << "Lista: ";
	for (i = lista.begin(); i != lista.end(); i++) {
		cout << (*i) << "\t";
	}
}