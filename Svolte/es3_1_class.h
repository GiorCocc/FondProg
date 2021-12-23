#ifndef ES1
#define ES1

#include<iostream>
#include<cstdlib>
#include<cmath>


using namespace std;

template <class T> T max2(T primo, T secondo) {
	if (primo > secondo)
		return primo;
	else
		return secondo;
}

template <class T> T max3(T primo, T secondo, T terzo) {
	return max(max2(primo, secondo), terzo);
}

#endif // !ES1