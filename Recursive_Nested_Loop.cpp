#include <iostream>
using namespace std;

void *multiply(int A[], int B[], int p[], int m, int n, int i, int j)
{
    //Recursive nested loop
    if(m > i){
        if(n > j){
            p[i+j] += A[i]*B[j];
            multiply(A, B, p, m, n, i, j+1);
        }
        else{
            j = 0;
            multiply(A, B, p, m, n, i+1, j);
        }
    }
}   
    
// A utility function to print a polynomial
void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << poly[i];
        if (i != 0)
        cout << "x^" << i ;
        if (i != n-1)
        cout << " + ";
    }

}

// Driver program to test above functions
int main()
{
    // The following array represents polynomial 5 + 10x^2 + 6x^3
    int A[] = {5, 0, 10, 6};
    // The following array represents polynomial 1 + 2x + 4x^2
    int B[] = {1, 2, 4};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    cout << "First polynomial is \n";
    printPoly(A, m);
    cout << "\nSecond polynomial is \n";
    printPoly(B, n);
    
    // Initialize the product polynomial
    //I had to put these here so that it will not Initialize every time you call the function
    int *prod = new int[m+n-1];
    for (int i = 0; i<m+n-1; i++) prod[i] = 0;
    
    //do the recursive
    multiply(A, B, prod, m, n, 0, 0);
    
    cout << "\nProduct polynomial is \n";
    printPoly(prod, m+n-1);
    return 0;
}