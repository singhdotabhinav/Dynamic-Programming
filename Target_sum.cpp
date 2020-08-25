// Move all + sign to one side and all = sign to other side of subset
// Now it is similar to count the number of subset with given difference problem


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




//Leet Code Solution && Covering some basic edge cases!!
//Cnt is for '0's in the array. If we have n number of zeroes then we need to multiply out result of count of subsets with a sum to 2^n.  And we need to not consider this while calculating in bottom-up manner, hence the case " if(nums[i-1]==0) { dp[i][j] = dp[i-1][j] } ".
//For example: If we have 2(cnt=2) zeroes in the example array for which we calculate count of subset with a sum then there are 4(2^cnt) ways that is either selecting first zero, second selecting second 0 present in array, third not selecting both, fourth selecting both.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int cnt = 0,sum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum = sum+nums[i];
            if(nums[i]==0)
                cnt = cnt+1;
        }
        if(S > sum)
            return 0;
        if((S+sum)%2!=0)
            return 0;
        int s = (S+sum)/2;
        int dp[n+1][s+1];
        for(int i=0;i<n+1;i++)
            dp[i][0] = 1;
        for(int j=1;j<s+1;j++)
            dp[0][j] = 0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<s+1;j++)
            {
                if(nums[i-1]==0)
                    dp[i][j] = dp[i-1][j];
                else if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        
        return pow(2,cnt)*dp[n][s];
    }
};

