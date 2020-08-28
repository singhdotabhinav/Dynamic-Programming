//Recursive code
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


//Recursive code with memoization

#include <bits/stdc++.h>
using namespace std;

static int t[100][100];

bool isPallindrome(string s, int i, int j){

    while(i<j){
            if(s[i++]!=s[j--])
                return false;
    }
    return true;
}
int solve( string s, int i, int j){
    if(i>=j)
        return t[i][j]=0;

    if(t[i][j]!=-1)
        return t[i][j];

    if(isPallindrome(s, i, j))
        return t[i][j] =0;

    int ans=INT_MAX;
    for(int k=i;k<j;k++){

        int temp =solve(s,i,k) + solve(s, k+1, j) + 1;
        ans=min(temp,ans);
    }
    t[i][j]=ans;
    return t[i][j];
}


int main()
{

    int arr[] = {40, 20, 30, 10, 30};
    string s="aabb";
    int n=s.length();

    memset( t, -1, sizeof(t));
    
    cout<<solve(s, 0, n-1)<<"\n";
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            cout<<t[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}

//Recursive solution memoized + optimization

#include <bits/stdc++.h>
using namespace std;

static int t[100][100];

bool isPallindrome(string s, int i, int j){

    while(i<j){
            if(s[i++]!=s[j--])
                return false;
    }
    return true;
}
int solve( string s, int i, int j){
    if(i>=j)
        return t[i][j]=0;

    if(t[i][j]!=-1)
        return t[i][j];

    if(isPallindrome(s, i, j))
        return t[i][j] =0;

    int ans=INT_MAX;

    for(int k=i;k<j;k++){
        int left,right;

        if(t[i][k]!=-1)
            left= t[i][k];
        else
            left=solve(s,i,k);

        if(t[k+1][j]!=-1)
            right= t[k+1][j];
        else
            right=solve(s,k+1,j);

        int temp=1+left+right;
        ans=min(temp,ans);
    }
    t[i][j]=ans;
    return t[i][j];
}


int main()
{

    string s="aabb";
    int n=s.length();
    memset( t, -1, sizeof(t));
    cout<<solve(s, 0, n-1)<<"\n";
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            cout<<t[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}



