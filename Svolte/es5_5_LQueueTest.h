// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LQUEUETEST_H
#define LQUEUETEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> // Used by timing functions

using namespace std;

#include "lqueue.h"

// Your basic int type as an object.
class Item
{
private:
	int val;

public:
	Item(int input = 0) { val = input; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int key() const { return val; }
	bool operator!=(const Item &other) const
	{
		if (val != other.key())
			return true;
		else
			return false;
	}
};

// Let us print out Items easily
inline ostream &operator<<(ostream &s, const Item &i)
{
	return s << i.key();
}

// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s)
{
	if (!val)
	{ // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}

// Print the queue
template <typename E>
void Lqueueprint(LQueue<E> &Q)
{
	for (int i = 0; i < Q.length(); i++)
	{
		E dequeued = Q.dequeue();
		cout << dequeued << " ";
		Q.enqueue(dequeued);
	}
}

template <typename E>
int equal_queues(LQueue<E> &Q1, LQueue<E> &Q2)
{
	if (Q1.length() != Q2.length()) //controllo se hanno la stessa lunghezza
		return 0;					//false se hanno lunghezza diversa
	while (Q1.length() > 0)			//controllo i singoli elementi se supero il primo test
	{
		E q1 = Q1.dequeue(); //estraggo un elemento
		E q2 = Q2.dequeue(); //estraggo un elemento
		if (q1 != q2)		 //controllo se coincidono
			return 0;		 //false se sono diversi
	}
	return 1; //true se supero tutti i test
}

#endif
