#include <stdio.h>
#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

string LCS( string X, string Y, int m, int n ){

    int t[m+1][n+1];
    for( int i = 0 ; i <= m ; i++ ){
        for( int j = 0 ; j <= n ; j++){
            if( i==0 || j==0 )
                t[i][j] = 0;
            else if ( X[i - 1] == Y[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = max( t[i-1][j] , t[i][j-1]);
        }
    }
    int i=m;
    int j=n;
    string s="";
    while( i>0 && j>0 ){
        if( X[i-1] == Y[j-1]){
            s.push_back( X[i-1] );
            i--;
            j--;
        }
        else{
            if( t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;
        }

    }
    reverse(s.begin(),s.end());

    return s;

}


int main()
{
    string X = "ABCDE";
    string Y = "ABDEF";


    int M = X.size();
    int N = Y.size();




    cout<<"Length of LCS is "<< LCS( X, Y, M, N ) ;

    return 0;
}
