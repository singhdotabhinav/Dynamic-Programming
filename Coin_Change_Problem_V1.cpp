#include <stdio.h>
#include<iostream>
using namespace std;

//Combination of unbounded knapsack and subset sum problem
int CoinChange(int coin[], int n, int sum)
{

    int subset[n + 1][sum + 1];



    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;


    for (int i = 1; i <= sum; i++)
        subset[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < coin[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= coin[i - 1])
                subset[i][j] = subset[i - 1][j] + subset[i ][j - coin[i - 1]];
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
    int Coin[] = { 1,2,3 };
    int sum = 4;
    int n = sizeof(Coin) / sizeof(Coin[0]);
    int c=CoinChange(Coin, n, sum);
    cout<<c;

    return 0;
}
