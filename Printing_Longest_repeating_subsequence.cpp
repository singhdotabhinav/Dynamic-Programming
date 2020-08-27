#include <stdio.h>
#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

string longestDupSubstring(string str) {

    int n = str.length();
    int t[n+1][n+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            t[i][j] = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (str[i-1] == str[j-1] && i != j)
                t[i][j] =  1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i][j-1], t[i-1][j]);


   
    string res = "";
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
       
        if (str[i-1]==str[j-1]  && i!=j)
        {
           res = res.push_back(str[i-1]);
           i--;
           j--;
        }

        else if (t[i][j] == t[i-1][j])
            i--;
        else
            j--;
    }

    reverse(res.begin(), res.end());

    return res;

    }

int main()
{
    string X = "aabebcdd";
    
    cout<<"Length of LCS is "<< longestDupSubstring(X) ;



    return 0;
}
