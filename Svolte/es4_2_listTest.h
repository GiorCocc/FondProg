#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"


class Item {
private:
  string abbreviazione;
  string parola;
public:
    Item(string a = "", string p = "") { abbreviazione = a; parola = p; }
  string key() const { return abbreviazione; }
  string getParola() const { return parola; }
  void setParola(string p) { parola = p; }
};


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
  { return s << i.key(); }
  
// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << endl;
    exit(-1);
  }
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
  int currpos = L.currPos();

  L.moveToStart();

  cout << "< ";
  int i;
  for (i=0; i<currpos; i++) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << "| ";
  while (L.currPos()<L.length()) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << ">\n";
  L.moveToPos(currpos); // Reset the fence to its original position
}



#endif

