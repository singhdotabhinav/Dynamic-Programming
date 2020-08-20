
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
    int set[] = { 2,3,5,6,8,10 };
    int sum = 10;
    int n = sizeof(set) / sizeof(set[0]);



    int c=CountSubsetSum(set, n, sum);
    cout<<c;

    return 0;
}
