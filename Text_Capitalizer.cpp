#include <iostream>
#include <string>
using namespace std;

//Captitalizes the first letter of words
int main()
{
    string s;
    getline(cin, s);
    for(int i = 0; i < s.length(); ++i) (s[i-1] == ' ' || i == 0) ? s[i] = toupper(s[i]) : s[i] = tolower(s[i]);
    cout << s << endl;
    return 0;
}