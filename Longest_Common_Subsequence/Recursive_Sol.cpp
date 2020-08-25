#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int LCS( string X, string Y, int m, int n ){
    if( n==0 || m==0 )
        return 0;
    if( X[ m - 1 ] == Y[ n - 1 ] )
        return 1 + LCS( X , Y , m-1 , n-1);

    else
        return max( LCS( X , Y , m , n-1 ) , LCS( X , Y , m-1 , n) );
}


int main()
{
    string X = "ABHINAV KUMAR";
    string Y = "SINGH SOLANKI";

    int M = X.size();
    int N = Y.size();


    cout<<"Length of LCS is "<< LCS( X, Y, M, N ) ;

    return 0;
}
