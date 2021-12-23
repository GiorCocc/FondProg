#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> // Used by timing functions
using namespace std;

#include "list.h"
#include "es9_1_symbol_table_item.h"

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

//funzione per l'inserimento ordinato all'interno della lista
inline void insertOrdered(List<Item> &L, const Item &item)
{
  if (L.length() == 0)
  {
    L.insert(item);
    return;
  }

  for (L.moveToStart(); L.currPos() < L.length(); L.next())
  {
    //se l'oggetto passato è più piccolo (come chiave) dell'elemento corrente, inserisco
    if (item.key() < L.getValue().key())
    {
      L.insert(item);
      return;
    }
    //quando le chiavi sono uguali, fondo i due elementi
    else if (item.key() == L.getValue().key())
    {
      Item rimosso = L.remove();
      rimosso.setInfo(rimosso.getinfo() + item.getinfo());
      L.insert(rimosso);
      return;
    }
  }
  L.append(item);
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E> &L)
{
  int currpos = L.currPos();

  L.moveToStart();

  cout << "< ";
  int i;
  for (i = 0; i < currpos; i++)
  {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << "| ";
  while (L.currPos() < L.length())
  {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << ">\n";
  L.moveToPos(currpos); // Reset the fence to its original position
}

#endif
