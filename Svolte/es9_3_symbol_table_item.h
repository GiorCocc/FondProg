#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h> // Used by timing functions
#include <string>
#include <iostream>
using namespace std;

static int maxKey = 100000;

typedef int Key;

class Item
{
private:
    string nome, email;
    int voto;
    Key matricola;

public:
    Item(string n = "", int v = 0, string e = "", Key k = maxKey)
    {
        nome = n;
        voto = v;
        email = e;
        matricola = k;
    }
    int getVoto() const { return voto; }
    string getNome() const { return nome; }
    Key key() const { return matricola; }
    int null() { return matricola == maxKey; }
    void setValue(string n, int v, string e)
    {
        nome = n;
        voto = v;
        email = e;
    }
    void show(ostream &os = cout) { os << matricola << endl; }
};

inline ostream &operator<<(ostream &os, const Item &x)
{
    return os << x.key();
}

#endif