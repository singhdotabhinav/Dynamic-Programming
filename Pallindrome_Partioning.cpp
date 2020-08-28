
#include <bits/stdc++.h>
using namespace std;


bool isPallindrome(string s, int i, int j){

    while(i<j){
            if(s[i++]!=s[j--])
                return false;
    }
    return true;
}
int solve( string s, int i, int j){
    if(i>=j)
        return 0;
    if(isPallindrome(s, i, j))
        return 0;
    int ans=INT_MAX;
    for(int k=i;k<j;k++){

        int temp =solve(s,i,k) + solve(s, k+1, j) + 1;
        ans=min(temp,ans);
    }
    return ans;
}


int main()
{

  
    string s="ababbbabbababa";
    int n=s.length();

    cout<<solve(s, 0, n-1);
   

    return 0;
}
