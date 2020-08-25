//Similar  to longest common subsequence
//In this problem we need to find maximum possible contiguous substring
//If string did'nt match make it again count from 0, so make it t[i][j] = 0;
//Just traverse through the matrix once and store max value in a variable and return that.
//Cuz substring can exist anywhere in between.

#include <stdio.h>
#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
int LCS( string X, string Y, int m, int n ){

    int t[m+1][n+1];
    for( int i = 0 ; i <= m ; i++ ){
        for( int j = 0 ; j <= n ; j++){
            if( i==0 || j==0 )
                t[i][j] = 0;
            else if ( X[i - 1] == Y[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = 0;
        }
    }
    int maxElement = INT_MIN;
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (t[i][j] > maxElement) {
                maxElement = t[i][j];
            }
        }
    }
    return maxElement;

}


int main()
{
    string X = "ABCDE";
    string Y = "ABCEF";


    int M = X.size();
    int N = Y.size();




    cout<<"Length of LCS is "<< LCS( X, Y, M, N ) ;

    return 0;
}
