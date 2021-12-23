#include"es3_2_class.h"
#include<string>

using namespace std;

int main() {
	int vettore[10] = { 1,2,3,4,5,6,7,8,9 };
	string stringhe[10] = { "alberto", "giovanni", "antonio", "pippo", "antonello", "giovanni", "antonio", "pippo", "antonio" };
	cout << "Nel vettore { 1,2,3,4,5,6,7,8,9 } si ripete piu\' volte: " << most_common(vettore, 10) << endl;
	cout << "Nel vettore { \"alberto\", \"giovanni\", \"antonio\", \"pippo\", \"antonello\", \"giovanni\", \"antonio\", \"pippo\", \"antonio\" } si ripete piu\' volte: " << most_common(stringhe, 9) << endl;
}