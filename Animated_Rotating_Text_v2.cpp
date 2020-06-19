#include<iostream>
#include<algorithm>
#include <windows.h>
using namespace std;

void clear(){
	Sleep(80); // delay 80 milisecons
	system("CLS");
}

int main()
{
	int i, j, k;
	string s;
	cout << "Enter word: ";
	getline(cin,s);
	while(true)
	{
		cout << s;
		clear();
		//slant
		for(i = 0; i < s.length(); ++i){
			for(j = 0; j < i; ++j){
				for(k = 0; k < j; ++k) cout << " ";
				cout << s[j] << endl;
			}
			for(j = 0; j < i; ++j) cout << " ";
			for(j = i; j < s.length(); ++j) cout << s[j];
			cout << endl;
			clear();
		}
		//straight
		for(i = 0; i < s.length(); ++i){
			for(j = 0; j < s.length(); ++j){
			for(k = 0; k < j-i; ++k) cout << " ";
			cout << s[j] << endl;
			}
			clear();
		}
		//slant again
		for(i = 0; i < s.length(); ++i)
		{
			for(j = 0; j < s.length(); ++j)
			{
			for(k = 0; k < i-j; ++k) cout << " ";
			cout << s[j] << endl;
			}
			clear();
		}
		//going backwards
		for(i = s.length()-1; i >= 0; --i){
			for(j = 0; j < s.length(); ++j){
				if(i > j){
					for(k = 0; k < s.length()-j; ++k) cout << " ";
					cout << s[j] << endl;
				}
				if(i == j){
				for(k = s.length()-1; k >= j; --k) cout << s[k];
				cout << endl;
				}
			}
			clear();
		}
		reverse(s.begin(),s.end());
	}
	return 0;
}
