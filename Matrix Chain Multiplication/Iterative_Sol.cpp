
#include <bits/stdc++.h>
using namespace std;

int mcm(int arr[],int n){

    int t[101][101];
    int i, j, k, l;

    for(int i=0; i<n; i++)
        t[i][j]=0;

    for(int l=2; l<n; l++){
        for(int i=1; i<=n-l; i++ ){

            int j=i+l-1;
            t[i][j] = INT_MAX;

            for(int k=i ; k<j;k++)
                t[i][j]=min(t[i][j], t[i][k] + t[k+1][j] + arr[i-1] * arr[k] * arr[j]);


        }
    }
    return t[1][n-1];
}

int main()
{

    int arr[] = {1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    
    cout<<mcm(arr,n);



    return 0;
}
