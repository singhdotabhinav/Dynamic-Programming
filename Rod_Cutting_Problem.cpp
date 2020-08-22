// A Dynamic Programming based
//Rod cutting problem similar to unbounded knapsack problem
//we are given price array, we need to cut the rod in such a way that we maximize the profit
//Mapping
//wt[] => length[](May not be given, construct it using given length of elements)
//val[] => price[]
//W(weight of knapsack) => N(length of array)
//K[n + 1][W + 1] => k[n+1][N+1]
#include <stdio.h>
#include<iostream>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(
                    val[i - 1] + K[i][w - wt[i - 1]],//only one change from 0/1 knapsack problem,
                    K[i - 1][w]);                    //replace K[i-1][w - wt[i - 1]] with K[i][w - wt[i - 1]]
            else                                     //if we take an element we can retake it, so we will process whole array again
                K[i][w] = K[i - 1][w];
        }
    }
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            cout<< K[i][w]<<"\t";
        }
        cout<<"\n";
    }

    return K[n][W];
}

int main()
{
    int val[] = { 1, 5, 8, 9, 10, 17, 17, 20 };

    int n = sizeof(val) / sizeof(val[0]);
    int wt[n];
    for(int i=0;i<n;i++){
        wt[i]=i+1;
    }


    printf("%d", knapSack(n, wt, val, n));
    return 0;
}
