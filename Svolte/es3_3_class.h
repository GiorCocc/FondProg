#ifndef ES1
#define ES1

#include<iostream>
#include<cstdlib>
#include<cmath>


using namespace std;

template<class T> class Pair{
private:
	T first;
	T second;
public:
	Pair(){}
	Pair(T f, T s) { 
		first = f;
		second = s;
	}
	void set_element(int position, T value);	// imposta value in posizione 1 o 2
	T get_element(int position) const;			// restituisce l’elemento in posizione 1 o 2 
	void add_up(const Pair<T>& the_pair);		// somma gli elementi corrispondenti di un oggetto Pair con quelli contenuti nell’argomento the_pair
};

template<class T> void Pair<T>::set_element(int position, T value) {
	if (position == 1)
		first = value;
	else if (position == 2)
		second = value;
	else {
		cout << "Errore!";
		exit(1);
	}
}

template<class T> T Pair<T>::get_element(int position) const {
	if (position == 1)
		return first;
	else if (position == 2)
		return second;
	else {
		cout << "Errore!";
		exit(1);
	}
}

template<class T> void Pair<T>::add_up(const Pair<T>& the_pair) {
	first += the_pair.first;
	second += the_pair.second;
}

#endif // !ES1