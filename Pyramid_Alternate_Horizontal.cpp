#include <iostream>
using namespace std;
int main(){
int i, j, n;
cout << "Size: "; cin >> n;
for(i = 0; i <= (n*2); ++i){
if(i <= n){
for(j = 0; j < i; ++j){
if(i%2 == 0) j%2 == 0 ? cout << "*" : cout << " ";
else j%2 == 0 ? cout << " " : cout << "*";
}
}
else{
for(j = i; j <= (n*2); ++j){
j%2 == 0 ? cout << "*" : cout << " ";
}
}
cout << endl;
}
return 0;
}
