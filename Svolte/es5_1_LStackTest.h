#ifndef LSTACKTEST_H
#define LSTACKTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> // Used by timing functions

using namespace std;

#include "lstack.h"

class Item
{
private:
	int val;

public:
	Item(int input = 0) { val = input; }
	int key() const { return val; }
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

// Print out the stack
template <typename E>
void Lstackprint(LStack<E> &S)
{
	LStack<E> Stemp;
	while (S.length() > 0)
	{
		E popped = S.pop();
		cout << popped << " ";
		Stemp.push(popped);
	}
	while (Stemp.length() > 0)
	{
		E popped = Stemp.pop();
		S.push(popped);
	}
}

// Transfer stack1 into stack2
template <typename E>
void LstackTransfer(LStack<E> &S1, LStack<E> &S2)
{
	LStack<E> Stemp;
	while (S1.length() > 0)
	{
		E popped = S1.pop();
		Stemp.push(popped);
	}
	while (Stemp.length() > 0)
	{
		E popped = Stemp.pop();
		S1.push(popped);
		S2.push(popped);
	}
}

template <typename E>
void Reverse(LStack<E> &S)
{
	LStack<E> stackTemp;			 //creo uno stack temporaneo
	LstackTransfer<E>(S, stackTemp); //trasferisco gli elementi dallo stack di partenza a quello temporaneo
	S.clear();						 //pulisco lo stack di partenza
	while (stackTemp.length() > 0)	 //per ogni elemento dello stack temporaneo
	{
		E popped = stackTemp.pop(); //rimuovo un elemento
		S.push(popped);				//lo inserisco nello stack di partenza
	}
}

#endif
