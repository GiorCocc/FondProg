#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

#include "lstack.h"
#include "es5_1_LStackTest.h"

using namespace std;

int main() {
	LStack<Item> stack;
	srand(time(NULL));

	for (int i = 0; i < rand() % 20 + 1; i++)
		stack.push(rand() % 100);
	cout << "Stack: "; Lstackprint(stack); cout << endl;

	Reverse<Item>(stack);
	cout << "Reversed Stack: "; Lstackprint(stack); cout << endl;
}