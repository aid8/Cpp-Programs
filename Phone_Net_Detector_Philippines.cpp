#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<vector<string>> ns = {{"0917", "0927" ,"0977", "0905" ,"0935", "0994", "0906", "0936", "0995", "0915" ,"0945" ,"0996", "0916" ,"0955" ,"0997", "0917" ,"0956", "0926" ,"0975"}, 
    {"0813", "0920" ,"0949", "0900" ,"0921" ,"0950", "0907" ,"0928" ,"0951", "0908" ,"0929" ,"0970", "0909" ,"0930" ,"0971", "0910", "0931" ,"0980", "0911" ,"0938" ,"0981", "0912" ,"0939", "0989", "0913" ,"0940" ,"0992", "0914" ,"0946" ,"0998", "0918" ,"0947" ,"0999", "0919" ,"0948"},
    {"0922", "0923","0925", "0931", "0932", "0933", "0934", "0942", "0943", "0944"}
    };
    string net[3] = {"Globe/TM", "Smart/TNT", "Sun"};
    cout << "Enter Number: ";
    string s; cin >> s;
    int i, j, n = -1;
    
    if(s.length() != 11){
        cout << "it must be 11 digit" << endl;
        return 0;
    }
    
    s.resize (4);
    for(i = 0; i < ns.size(); ++i){
        if(n == -1){
            for(j = 0; j < ns[i].size(); ++j){
                if(ns[i][j] == s){
                    n = i;
                    break;
                }
            }
        } 
        else break;
    }
    if(n != -1) cout << "Ang number mo ay " << net[n] << endl;
    else cout << "Itong number na ito ay wala sa network" << endl;
    return 0;
}
