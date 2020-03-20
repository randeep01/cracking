#include <iostream>
#include <map>
using namespace std;

bool checkPerm(char* ptr) {
	map<char, int> m;
	map<char, int>::iterator iter;
	char* c = ptr;

	while (*c != NULL) {
		cout <<"insertin "<< *c<<endl;
		iter = m.find(*c);
		if (iter == m.end()) {
			m.insert(std::pair<char,int>(*c,1));

		}
		else {
			int val = iter->second;
			val++;
			//m.insert(std::pair<char,int>(*c, val));
			m.at(*c) = val;
		}
		c = ++ptr;
	}

	map<char, int>::iterator i;
	cout << endl;
	cout << endl;
	int odd = 0;
	for (i = m.begin(); i != m.end(); i++) {
		cout << i->first << " " << i->second << endl;

		if ((i->second) % 2 == 0) {
			cout << "even" << endl;
		}
		else {
			odd++;
			cout << "odd" << endl;
		}
	}
	cout << "odd " << odd<<endl;
	return odd<=1;
}
int main() {

	char str[20] = "rraab";
	cout<<"is permutation " << std::boolalpha<<checkPerm(str);


	return 0;
}