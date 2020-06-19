#include <iostream>
using namespace std;

int main()
{
	int n, i, j, l;
	cout << "Enter Number: "; cin >> n;
	for(i = 0; i < (n/4) + (n%2 == 0 ? 0 : 1); ++i){
		for(j = i; j < n - 1; ++j) cout << " ";
		cout << "*";
		if(i == 0) cout << endl;
		else{
			for(j = 0; j < (i*2) -1; ++j) cout << " ";
			cout << "*" << endl;
		}
	}
	for(i = 0; i < (n*2)-1; ++i) cout << "*";
	cout << endl;
	for(i = 0; i < n-1; ++i){
		for(j = 0; j <= i; ++j) {
			if(j == -(i-(n/2)+1)+(n/4) - ((n%4 == 0 || n%4 == 1) ? 1 : 0)) cout << "*";
			else if(i == n-(n/4)-(n%2 == 0 ? 2 : 3)) cout << "*";
			else cout << " ";
		}
		if(i != n-2)cout << "*";
		
		for(j = n; j > ((i-(n/2)+2)*2) + (n%2 == 0 ? 1 : 0); --j) {
			if(j == 1-(n/4) + (n%2 == 0 ? 1 : 0)) cout << "*";
			else if(j == n +((i-(n/2)+2)*2) + (n/4)) cout << "*";
			else if(i == (n/2)+(n/4)- ((n%4 == 0 || n%4 == 1) ? 2 : 1)) cout << "*";
			else cout << " ";
		}
		cout << "*";
		
		l = -(i-(n/2)+1)+(n/4) - ((n%4 == 0 || n%4 == 1) ? 1 : 0);
		if(i >= l){
			for(j = 0; j < ((i-(n/2)+2)*2) + (n/4) - 2; ++j) {
				if(i == (n/2)+(n/4)- ((n%4 == 0 || n%4 == 1) ? 2 : 1)) cout << "*";
				else cout << " ";
			}
			if(l >= 0)cout << '*';
		}
		cout << endl;
	}
	return 0;	
}
