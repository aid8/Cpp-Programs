#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> n;
	int g = -2, i, j, l = 0;
	cout << "Enter Numbers (-1 to stop): "; cin >> g;
	cout << endl;
	while(g != -1){
		n.push_back(g+1);
		cin >> g;
	}
	for(i = 0; i < n.size(); ++i) if(n[i] > l) l = n[i];
	int m[l][n.size()];
	for(i = 0; i < n.size(); ++i){
		for(j = 0; j < l; ++j){
			if(j >= n[i]) m[l-j-1][i] = 0;
			else m[l-j-1][i] = 1;
		}
	}
	for(i = 0; i < l; ++i){
		for(j = 0; j < n.size(); ++j){
			if(m[i][j] == 1){
				if(l-i == n[j] || i == l-1) cout << "***";
				else cout << "* *";
			}
			else cout << "   ";
		}
		cout << endl;
	}
	return 0;
}

/*

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> n;
	int g = -2, i, j, l = 0;
	cout << "Enter Numbers (-1 to stop): "; cin >> g;
	cout << endl;
	while(g != -1){
		n.push_back(g+1);
		cin >> g;
	}
	for(i = 0; i < n.size(); ++i) if(n[i] > l) l = n[i];
	int m[l][n.size()];
	for(i = 0; i < n.size(); ++i){
		for(j = 0; j < l; ++j) j >= n[i] ? m[l-j-1][i] = 0 : m[l-j-1][i] = 1;
	}
	for(i = 0; i < l; ++i){
		for(j = 0; j < n.size(); ++j){
			if(m[i][j] == 1) (l-i == n[j] || i == l-1) ? cout << "***" : cout << "* *";
			else cout << "   ";
		}
		cout << endl;
	}
	return 0;
}
*/

