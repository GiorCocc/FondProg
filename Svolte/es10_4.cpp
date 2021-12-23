#include<iostream>
#include<sstream>
#include<fstream>
#include<ctime>
#include<map>
#include<string>
#include<set>

using namespace std;

bool Find_terno(map<string, set<int> >& lotto, string ruota, int n1, int n2, int n3) {
	map<string, set<int>>::iterator it = lotto.find(ruota);

	if (it == lotto.end()) return false;
	if (it->second.find(n1) != it->second.end() && (it->second.find(n2) != it->second.end()) && (it->second.find(n3) != it->second.end()))
		return true;
	else
		return false;
}

int main() {
	map<string, set<int> > lotto;
	string ruota;
	int n1, n2, n3, n4, n5;

	ifstream file("lotto.txt");
	if (file.is_open()) {
		while (file >> ruota >> n1 >> n2 >> n3 >> n4 >> n4) {
			set<int> numeri_estratti;
			numeri_estratti.insert(n1);
			numeri_estratti.insert(n2);
			numeri_estratti.insert(n3);
			numeri_estratti.insert(n4);
			numeri_estratti.insert(n5);
			lotto.insert(pair<string, set<int>>(ruota, numeri_estratti));
		}
	}
	file.close();

	cout << "Terno (11,12,13) ruota di Firenze: " << Find_terno(lotto, "Firenze", 11, 12, 13) << endl;
	cout << "Terno (46,84,3) ruota di Milano: " << Find_terno(lotto, "Milano", 46, 84, 3) << endl;

}