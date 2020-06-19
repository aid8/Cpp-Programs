/*Challenge Flames Solution
A program that tells your future with your crush :)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2, sO = "";
    string ft[6] = {"Friends", "Lovers", "Angry", "Married", "Enemies", "Soulmate"};
	cout << "Enter your name: "; getline(cin, s1); 
	cout << "Enter your crush name: "; getline(cin, s2);
	
    int i, n = 0, a;
    
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    for(i = 0; i < s1.length(); ++i){
        if((count(s2.begin(), s2.end(), s1[i]) > 0) && (count(sO.begin(), sO.end(), s1[i]) <= 0)){
            n += count(s2.begin(), s2.end(), s1[i]) + count(s1.begin(), s1.end(), s1[i]);
            sO += s1[i];
        }
    }
    
    a = (s1.length()+s2.length()) - n;

    cout << "The Value is " << a << endl;
    if(a == 0) cout << "The Same" << endl;
    else cout << "The two of you are " << ft[(a % 6) - 1] << endl;
    return 0;
}
