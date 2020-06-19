#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

void clear(){
	Sleep(80); // delay 80 milisecons
	system("CLS");
}

int main()
{
	cout << "Enter word: ";
	string s; getline(cin,s);
	int i, j, k;
	system("CLS");
	
	while(true){
		for(i = 0; i < s.length()/2; ++i) cout << endl;
		cout << s;
		clear();
		
		for(k = 1; k < (s.length()/2)+1; ++k){
			for(i = 0; i < (s.length()/2)-k; ++i) cout << endl;
			for(i = 0; i < k; ++i) { 
				for(j = 0; j < s.length()-i-1; ++j) cout << " ";
				cout << s[s.length()-i-1];
				if(s.length()%2 == 0){
					if(i != (s.length()/2)-1) cout << endl;
				}
				else cout << endl;
			}
			for(i = 0; i < k; ++i) cout << " ";
			for(i = k; i < s.length()-k; ++i) cout << s[i];
			cout << endl;
			for(i = 0; i < k; ++i){
				for(j = 0; j < k-i-1; ++j) cout << " ";
				cout << s[k-i-1] << endl;
			}
			clear();
		}
		
		for(k = 1; k < (s.length()/2)+1; ++k){
			for(i = 0; i < k; ++i) {
				for(j = 0; j < s.length()-k; ++j) cout << " ";
				cout << s[s.length()-1-i] << endl;
			}
			for(i = k; i < s.length()-k; ++i){
				for(j = 0; j < s.length()-1-i; ++j) cout << " ";
				cout << s[s.length()-i-1] << endl;
			}
			for(i = 0; i < k; ++i){
				for(j = 0; j < k-1; ++j) cout << " ";
				cout << s[k-i-1] << endl;
			}
			clear();
		}
		
		for(k = 0; k < (s.length()/2)+1; ++k){
			for(i = 0; i < k; ++i){
				for(j = 0; j < (s.length()/2)-k+i; ++j) cout << " ";
				cout << s[s.length()-i-1] << endl;
			}
			
			for(i = k; i < s.length()-k; ++i){
				for(j = 0; j < (s.length()/2); ++j) cout << " ";
				cout << s[s.length()-i-1] << endl;
			}
			
			for(i = 0; i < k; ++i){
				for(j = 0; j < (s.length()/2)+i+(s.length()%2 == 0 ? 0:1); ++j) cout << " ";
				cout << s[k-i-1] << endl;
			}
			clear();
		}
		
		for(k = 2; k < (s.length()/2)+1; ++k){
			for(i = 1; i < k; ++i) cout << endl;
			for(j = 0; j < i; ++j) cout << s[s.length()-j-1];
			cout << endl;
			for(i = k; i < s.length()-k; ++i){
				for(j = 0; j < i; ++j) cout << " ";
				cout << s[s.length()-i-1] << endl;
			}
			for(i = 0; i < s.length()-k; ++i) cout << " ";
			for(i = 0; i < k; ++i) cout << s[k-i-1];
			cout << endl;
			clear();
		}
		
		for(i = 1; i < k; ++i) cout << endl;
		reverse(s.begin(),s.end());
		cout << s << endl;
		clear();
	}
	return 0;
}
