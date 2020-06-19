#include <iostream>
#include <windows.h>
using namespace std;
//AnimatedTextBorder
void clear(){
	Sleep(80);
	system("CLS");
}
int main()
{
	string s;
	int sp,i,j,k = 0,c = 0,b = 0;
	cout << "Enter Text: "; getline(cin, s);
	cout << "Enter Space Size: "; cin >> sp; sp+=2;
	if(sp < 1){
		cout << "Please input greater than 1";
		return 0;
	}
	while(true){
		for(i = 0; i < sp; ++i) i == b ? cout << "^" : cout << "*";
		cout << endl;
		for(i = sp-1; i >= 0; --i){
			if(i == sp-1) b == (sp*2)+2 ? cout << "<" :cout << "*";
			else if(i == 0) b == sp+1 ? cout << ">" :cout << "*";
			else if(i <= k && k-i <= s.length()-1) cout << s[k-i];
			else cout << " ";
		}
		cout << endl;
		for(i = sp-1; i >=0 ; --i) b-sp-2 == i ? cout << "V" : cout << "*";
		clear();
		if(k == sp+s.length()-1) c < 3 ? c++ : c = 0;
	    (k < sp+s.length()-1) ? k++ : k = 0;
	    if(c == 0) system("color A"); //Green
	    else if(c == 1) system("color B"); //Blue
	    else if(c == 2)system("color C"); //Red
	    else system("color E"); //Yellow
	    (b < (sp*2) + 2) ? b++ : b = 0;
	}
	return 0;
}
