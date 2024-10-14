//CODING NINJAS Maximum sum of non-adjacent elements
#include <bits/stdc++.h> 
int helper(vector<int>& dp,vector<int> &nums, int n)
{
    if(n==0)
    return nums[0];
    if(n<0)
    return 0;

    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=max(nums[n]+helper(dp,nums,n-2),helper(dp,nums,n-1));
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
   vector<int> dp(n+1,-1);
    return helper(dp,nums,n-1);
}
// SC=O(N)
// TC=O(N)



//*****************************************************************

#include <bits/stdc++.h> 
//tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
   vector<int> dp(n+1,-1);
    dp[0]=nums[0];
    int pick=0;
    int npick=0;
    for(int i=1;i<n;i++)
    {
        pick=nums[i];
        if(i-2>=0)
        pick+=dp[i-2];
        
        npick=dp[i-1];
        
        dp[i]=max(pick,npick);
    }
    return dp[n-1];
}
// SC=O(N)
// TC=O(N)

//*****************************************************************
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
   vector<int> dp(n+1,-1);
    dp[0]=nums[0];
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++)
    {
        int x=nums[i];
        if(i-2>=0)
        x+=prev2;
        
        int y=prev;
        
        int curr=max(x,y);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
// SC=O(1)
// TC=O(N)