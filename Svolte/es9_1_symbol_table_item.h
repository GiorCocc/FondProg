#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h> // Used by timing functions
#include <string>
#include <iostream>
using namespace std;

static int maxKey = 1000;

typedef int Key;

class Item
{
private:
  string info;
  Key keyval;

public:
  Item(string s = "", Key k = maxKey)
  {
    info = s;
    keyval = k;
  }
  Key key() const
  {
    return keyval;
  }
  int null()
  {
    return keyval == maxKey;
  }

  // genera casualmente i dati (chiave, valore) di un elemento
  void random_element()
  {
    keyval = 1000 * (1.0 * rand() / RAND_MAX);
    info = 1.0 * (1.0 * rand() / RAND_MAX);
  }

  // legge da tastiera i dati (chiave, valore) di un elemento
  int scan(istream &is = cin)
  {
    is >> keyval >> info;
    return !(cin.fail());
  }
  void show(ostream &os = cout)
  {
    os << keyval << " " << info << endl;
  }

  string getinfo() const { return info; }
  void setInfo(string i) { info = i; }
};

inline ostream &operator<<(ostream &os, const Item &i)
{
  return os << "(" << i.key() << " " << i.getinfo() << ")";
}

#endif