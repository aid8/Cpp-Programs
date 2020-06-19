#include<iostream>
using namespace std;

int main()
{
    int i, j, k;
    string s;
    cout << "Enter word: ";
    getline(cin,s);
    cout << endl;
    for(i = 0; i < s.length(); ++i) {
        s.length() % 2 == 0 ? k = 1 : k = 0;
        if(i < (s.length()/2)-k) {
            for(j = 0; j < i+k; ++j) cout << " ";
            cout << s[i];
            for(j = 0; j < (s.length()/2)-1-i-k; ++j) cout  << " ";
            cout << s[i];
            for(j = 0; j < (s.length()/2)-1-i-k; ++j) cout  << " ";
            cout << s[i] << endl;
        }
        else if(i == (s.length()/2)-k){
            if(k == 1) cout << " ";
            cout << s << endl;
        }
        else{
            for(j = 0; j < s.length()-i-1; ++j) cout << " ";
            cout << s[i];
            for(j = (s.length()/2)-k+1; j < i; ++j) cout  << " ";
            cout << s[i];
            for(j = (s.length()/2)-k+1; j < i; ++j) cout  << " ";
            cout << s[i] << endl;
        }
    }
    return 0;
}
