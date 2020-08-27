//With memoization
#include <bits/stdc++.h>
using namespace std;

static int t[5][5];
int MCM(int arr[] ,int i , int j){

    if( i >= j  ){
        t[i][j]=0;
        return 0;
    }
    if(t[i][j]!=-1)
        return  t[i][j];

    int mn=INT_MAX;
    for(int k=i ; k< j ; k++){

        int cost = MCM( arr , i , k ) + MCM( arr , k+1 , j ) + arr[i-1] * arr[k] * arr[j];

        mn=min(cost,mn);
    }
    t[i][j]=mn;
    return mn;
}

int main()
{

    int arr[] = {1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    memset( t, -1, sizeof(t));
    cout<<MCM(arr,1,n-1);



    return 0;
}
