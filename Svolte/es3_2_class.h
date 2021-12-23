#ifndef ES1
#define ES1

#include<iostream>
#include<cstdlib>
#include<cmath>


using namespace std;

template <typename T> T most_common(T* A, int size) {
	T v = A[0];
	int frequenza = 0;
	int count;
	for (int i = 0; i < size; i++) {
		count = 0;
		for (int j = 0; j < size; j++) {
			if (A[i] == A[j])
				count++;
		}
		if (count > frequenza) {
			frequenza = count;
			v = A[i];
		}
	}
	return v;
}


#endif // !ES1