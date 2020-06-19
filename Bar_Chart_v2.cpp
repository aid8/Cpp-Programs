#include <iostream>
using namespace std;
int main()
{
	int g, i, j, l;
	cin >> g;
	int n[g];
	for(i = 0; i < g; ++i){
        cin >> n[i];
        if(n[i] > l) l = n[i];
	}
	int m[l][g];
	for(i = 0; i < g; ++i) for(j = 0; j < l; ++j) j >= n[i] ? m[l-j-1][i] = 0 : m[l-j-1][i] = 1;
	for(i = 0; i < l; ++i){
		for(j = 0; j < g; ++j)(m[i][j] == 0) ? cout << " " : cout << "*";
		cout << endl;
	}
	return 0;
}
