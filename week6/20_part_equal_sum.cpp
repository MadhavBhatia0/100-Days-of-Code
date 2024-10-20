//LC 416
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
        }
        if(total%2)
        return false;
        vector<vector<int>> dp(n,vector<int>(total/2+1,-1));
        return f(n-1,total/2,dp,nums);
    }
    bool f(int i,int target,vector<vector<int>>&dp, vector<int>& nums)
    {
        if(target==0)
        return true;
        if(i==0)
        return (nums[0]==target);
        if(dp[i][target]!=-1)
        return dp[i][target];

        int take=false;
        if(target>=nums[i])
        {
            take=f(i-1,target-nums[i],dp,nums);
        }
        int ntake=f(i-1,target,dp,nums);
        dp[i][target]=take||ntake;
        return dp[i][target];
    }
};
//O(N*TARGET) TC
//O(N*TARGET)+O(N) SC

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
        }
        if(total%2)
        return false;

        int sum=total/2;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        if(nums[0]<=sum)
        dp[0][nums[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum;target++)
            {
                int take=false;
                if(target>=nums[i])
                {
                    take=dp[i-1][target-nums[i]];
                }
                int ntake=dp[i-1][target];
                dp[i][target]=take||ntake;
            }
        }

        return dp[n-1][sum];
    }
};
//O(N*TARGET) TC
//O(N*TARGET) SC