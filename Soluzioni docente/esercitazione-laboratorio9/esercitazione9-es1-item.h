#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
#include <string>
using namespace std;

static int maxKey = 1000;
typedef int Key;

class Item 
  { 
    private:
      string info;
	  Key keyval;
    public:
      Item(string i="", Key k= maxKey)
        { 
		  info = i;
		  keyval = k; 
	    } 
      Key key() const
        { return keyval; }
      int null()
        { return keyval == maxKey; }
	  void setinfo(string i)
	  {
		  info = i;
	  }
	  string getinfo() const
	  {
		  return info;
	  }
   
      int scan(istream& is = cin)
        { 
		  is >> keyval >> info; 
		  return !(cin.fail());
	    }
      void show(ostream& os = cout)
        { os << keyval << " " << info << endl; }
   }; 

// Let us print out Items easily
inline ostream& operator<<(ostream& os, const Item& i)
  { return os << "(" << i.key() << " " << i.getinfo() << ")";
}

  
#endif