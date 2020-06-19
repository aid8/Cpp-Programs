#include <iostream>
using namespace std;

int main()
{
	cout << "Enter Text: ";
	string s; cin >> s;
	int i, j;
	for(i = 0; i < s.length(); ++i){
		for(j = i; j < s.length()-1; ++j) cout << " ";
		for(j = i; j >= 0; --j) cout << s[j];
		for(j = 1; j <= i; ++j) cout << s[j];
		cout << endl;
	}
	return 0;
}
