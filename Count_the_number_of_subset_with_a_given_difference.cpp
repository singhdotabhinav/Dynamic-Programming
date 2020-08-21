//s1-s2=Difference
//s1+s2=Sum(array)
//add both equations we get, 2s1=Sum(array)+Difference;=>s1=(Sum+Diff)/2
//Now we need to find two subset with a given sum
//Problem reduced to count subset of given sum
#include <stdio.h>
#include<iostream>
using namespace std;


int CountSubsetSum(int set[], int n, int sum)
{

    int subset[n + 1][sum + 1];



    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;


    for (int i = 1; i <= sum; i++)
        subset[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] + subset[i - 1][j - set[i - 1]];
        }
    }
    //printf ("%d\n",n);
    for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++){
        printf ("%d\t",subset[i][j]);
       }
        printf("\n");

    }
    return subset[n][sum];

}


int main()
{
    int set[] = { 1,1,2,3 };
    int sum = 0,diff=1;
    int n = sizeof(set) / sizeof(set[0]);
    
    for (int i = 0; i <= n; i++)
        sum+=set[i];
    int num=(sum+diff)/2;


    int c=CountSubsetSum(set, n, num);
    cout<<c;

    return 0;
}
