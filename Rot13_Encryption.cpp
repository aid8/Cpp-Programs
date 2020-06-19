#include<iostream>
using namespace std;

//Rotates the string character 13 times, making it encrypted
int main(){
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    for(int i = 0; i < s.length(); ++i){
        if(isalpha(s[i])){
            if(isupper(s[i])){
               s[i] += 13;
               if(s[i] > 90) s[i] = (64 + (s[i]-90));
            }
            else{
                if(int(s[i] + 13) > 122) s[i] = (96 + (int(s[i] + 13)-122));
                else s[i] += 13;
            }
        }
    }
    cout << "Encoded text: " << s << endl;
    return 0;
}
