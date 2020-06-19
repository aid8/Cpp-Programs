#include <iostream>
using namespace std;
int main()
{
	int ms[3][3];
	int c[9] ={0,0,0,0,0,0,0,0,0}; //check array
	int s[8] ={0,0,0,0,0,0,0,0}; //sum array
	int i,j,t;
	bool res = true;
	//Get input of user and check if numbers are not repeating
	for(i = 0; i < 3; ++i){
		if(!res) break;
		for(j = 0; j < 3; ++j){
			cin >> t;
			if(c[t-1] == 0) c[t-1] = 1;
			else{
				res = false;
				break;
			}
			ms[i][j] = t;		
		}
	}
	//if numbers are repeating, do not add and exit
	if(!res){
		cout << "It is not a Lo Shu Magic square.";
		return 0;
	}
	//else add them
	for(i = 0; i < 3; ++i){
		for(j = 0; j < 3; ++j) s[j] += ms[i][j]; // add horizontal
		for(j = 0; j < 3; ++j) s[j+3] += ms[j][i]; // add vertical
		s[6] += ms[i][i]; // add vertical left to right
		s[7] += ms[2-i][i]; // add vertical right to left
	}
	//cout << ms[0][1] << endl;
	t = s[0];
	for(i = 1; i < 8; ++i){
		if(t != s[i]){
			res = false;
			break;
		}
	}
	res ? cout << "It is a Lo Shu Magic square." : cout << "It is not a Lo Shu Magic square.";
}