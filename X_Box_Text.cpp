#include <iostream>
using namespace std;

int main()
{
	cout << "Enter text: ";
	string s; cin >> s;
	cout << endl;
	
	int i, j;
	for(i = 0; i < s.length(); ++i) cout << s[i] << " ";
	cout << endl;
	for(i = 1; i < s.length()-1; ++i){
	
		cout << s[i] << " ";
		if(i < s.length()/2){
			for(j = 1; j < i; ++j) cout << "  ";
			cout << s[i];
			for(j = 0; j < s.length() - (i*2) - 2; ++j) cout << "  ";
		    cout << " " << s[s.length()-1-i] << " ";
			for(j = 0; j < i-1; ++j) cout << "  ";
			cout << s[s.length()-1-i] << endl;
		}
		else if(i == s.length()/2 && (s.length() % 2 == 1)){
			for(j = 0; j < (s.length()/2)-1; ++j) cout << "  ";
			cout << s[i];
			for(j = 0; j < (s.length()/2)-1; ++j) cout << "  ";
			cout << " " << s[i] << endl;
		} 
		else{
			for(j = i; j < s.length()-2; ++j) cout << "  ";
			cout << s[i];
			for(j = 0; j < (i*2) - s.length(); ++j) cout << "  ";
			cout << " " << s[s.length()-1-i] << " ";
			for(j = i; j < s.length()-2; ++j) cout << "  ";
			cout << s[s.length()-1-i] << endl;
		}
		
	}
	for(i = 0; i < s.length(); ++i) cout << s[s.length()-1-i] << " ";
	return 0;
}
