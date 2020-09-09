class Solution {
public:
bool canPartition(vector<int>& nums) {

    int n=nums.size();
    long int sum=0;
    for(auto i:nums)
        sum+=i;
    
    if(sum%2!=0)  // if the sum is odd, there is no chance for that array to have two equal subsets
        return false;
    else
    {
        int w = sum/2;
        vector<vector<bool> > dp(n+1, vector<bool>(w+1,false)); 
                    
        for(auto i=0;i<n+1;i++) // initializing first column 
            dp[i][0] = true;
        
        for(auto i=1;i<n+1;i++)
            for(auto j=1;j<w+1;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        
        return dp[n][w];
    }
}
};



//Equivalent C code
bool isSubsetSum (int arr[], int n, int sum)  
{    
    if (sum == 0)  
        return true;  
    if (n == 0 && sum != 0)  
        return false;  

    if (arr[n-1] > sum)  
       return isSubsetSum (arr, n-1, sum);  
  
    return isSubsetSum (arr, n-1, sum) ||  
        isSubsetSum (arr, n-1, sum-arr[n-1]);  
}  

bool canPartition(int* nums, int n){
    
    int sum=0,i=0;
    for(int i=0;i<n;i++)
        sum+=nums[i];
    if((sum%2)!=0)
        return false;
    else
        return isSubsetSum(nums,n,sum/2);

}
