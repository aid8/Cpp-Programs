
#include <iostream>
using namespace std;

int main()
{
	int i, j, k, l;
	string s;
	cout << "Enter Text: ";
	getline(cin,s);
	cout << endl;
	
	if(s.length() == 1) cout << s;
	else{
		cout << s << endl;
		i = 1, j = s.length()-2;
		for(k = 0; k < s.length()-2; ++k){
			cout << s[i];
			for(l = 0; l < s.length()-2; ++l) cout << " ";
			cout << s[j] << endl;
			i++, j--;
		}
		for(k = 0; k < s.length(); ++k) cout << s[s.length()-1-k];
	}
	return 0;
}
