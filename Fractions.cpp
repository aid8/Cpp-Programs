#include <iostream>
#include <cmath>
using namespace std;

//Solution for no.1

int getGCD(int n1, int n2)
{
	//returns GCD of two numbers
	while(n1 != n2) (n1 > n2) ? n1 -= n2 : n2 -= n1;
	return n1;
}

void addFractions(int *n1, int *d1, int *n2, int *d2)
{
	int fd, fn, cf;
	//Getting LCM
	fd = (*d1 * *d2) / getGCD(*d1,*d2);
	//Getting same denom
	fn = (*n1) * (fd / *d1) + (*n2) * (fd / *d2);
	//Simplify by dividing their common factor
	cf = getGCD(fn,fd);
	fd /= cf;
	fn /= cf;
	//Output
	cout << *n1 << "/" << *n2  << " + " << *n2 << "/" << *d2 << " = "<< fn << "/" << fd << endl;
}

void subtractFractions(int *n1, int *d1, int *n2, int *d2)
{
	int fd, fn, cf;
	//Getting LCM
	fd = (*d1 * *d2) / getGCD(*d1,*d2);
	//Getting same denom
	fn = (*n1) * (fd / *d1) - (*n2) * (fd / *d2);
	//Simplify by dividing their common factor
	if(fn != 0){
		cf = getGCD(abs(fn),abs(fd));
		fd /= cf;
		fn /= cf;
	}
	//Output
	cout << *n1 << "/" << *n2  << " - " << *n2 << "/" << *d2 << " = "<< fn << "/" << fd << endl;
}

void multiplyFractions(int *n1, int *d1, int *n2, int *d2)
{
	int fd, fn, cf;
	//Getting LCM
	fd = (*d1 * *d2) / getGCD(*d1,*d2);
	//Getting same denom
	fn = (*n1) * (fd / *d1) * (*n2) * (fd / *d2);
	//Multiply denom by itself
	fd*=fd;
	//Simplify by dividing their common factor
	cf = getGCD(fn,fd);
	fd /= cf;
	fn /= cf;
	//Output
	cout << *n1 << "/" << *n2  << " * " << *n2 << "/" << *d2 << " = "<< fn << "/" << fd << endl;
}

void getLCD(int *d1, int *d2)
{
	//Gives LCM / LCD
	int lcd = (*d1 * *d2) / getGCD(*d1, *d2);
	cout << "LCD = " << lcd << endl;
}

int main()
{
	int n1, d1, n2, d2 , s;
	cout << "Enter first fraction: ";
	cin >> n1 >> d1;
	cout << "Enter second fraction: ";
	cin >> n2 >> d2;
	cout << "Operations : \n 1 - Add \n 2 - Subract \n 3 - Multiply \n 4 - LCD \nEnter Operation: ";
	cin >> s;
	
	if(s == 1) addFractions(&n1, &d1, &n2, &d2);
	else if(s == 2) subtractFractions(&n1, &d1, &n2, &d2);
	else if(s == 3) multiplyFractions(&n1, &d1, &n2, &d2);
	else if(s == 4) getLCD(&d1, &d2);
	else cout << "Invalid Operation Number Given!";
	return 0;
}