#include <iostream>
using namespace std;

int reduce(int &num, int &denom){
	int gcd, i;
	bool swapped = false;
	if(num <= 0 || denom <= 0) return 0;
	if(num > denom){
		swap(num,denom);
		swapped = true;
	}
	for (i = 1; i <= denom; ++i) 
		if (num % i == 0 && denom % i ==0) 
			gcd = i;	
	if(swapped) swap(num,denom);
	num /= gcd;
	denom /= gcd;
	return 1;
}

int main()
{
	int m, n;
	cout << "Enter two numbers: ";
	cin >> m >> n;
	if(reduce(m,n) == 1) cout << m << "/" << n << endl;
	else cout << "fraction error" << endl;
	return 0;	
}