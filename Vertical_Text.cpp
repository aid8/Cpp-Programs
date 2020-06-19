#include<iostream>
using namespace std;

int main(){
    string s;
    cout << "Enter Sentence: "; getline(cin,s);
    int i, j, m = 0, n = 0, mx = 0;
    char c[100][100];
    for(i = 0; i < s.length(); ++i){
        if(s[i] == ' '){
            if(m > mx) mx = m;
            m = 0;
            n++;
        }
        else{
            c[m][n] = s[i];
            m++;
        }
    }
    for(i = 0; i <= mx; ++i){
        for(j = 0; j <= n; ++j) cout << c[i][j];
        cout << endl;
    }
    return 0;
}
