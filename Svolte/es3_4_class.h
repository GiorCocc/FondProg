#ifndef ES1
#define ES1

#include<iostream>
#include<cstdlib>
#include<cmath>


using namespace std;

template <class T> class Matrix2x2 {
public:
	T m[2][2];
	Matrix2x2() {			//costruttore base
		m[0][0] = 0;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 0;
	}
	Matrix2x2(int m00, int m01, int m10, int m11);		//definizione per costruttore custom
	Matrix2x2<T> Add(Matrix2x2 x);
};

template<class T> Matrix2x2<T>::Matrix2x2(int m00, int m01, int m10, int m11) {
	m[0][0] = m00;
	m[0][1] = m01;
	m[1][0] = m10;
	m[1][1] = m11;
}

template<class T> Matrix2x2<T> Matrix2x2<T>::Add(Matrix2x2 x) {
	Matrix2x2<T> sum;

	sum.m[0][0] = m[0][0] + x.m[0][0];
	sum.m[0][1] = m[0][1] + x.m[0][1];
	sum.m[1][0] = m[1][0] + x.m[1][0];
	sum.m[1][1] = m[1][1] + x.m[1][1];

	return sum;

}

#endif // !ES1