//LEETCODE 322. Coin Change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int result=f(n-1,amount,dp,coins);
        return (result==INT_MAX)? -1:result;
    }
    int f(int ind,int amount,vector<vector<int>>& dp,vector<int>& arr){
        if(amount==0)
        return 0;

        if (ind < 0) 
        return INT_MAX;

        if(ind==0)
        {
            if (amount==arr[ind])
            {
                if(amount%arr[ind]==0)
                return amount/arr[ind];
                else
                return INT_MAX;
            }
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];

        int take = INT_MAX;
        if (arr[ind] <= amount) {
            int sub_res = f(ind, amount - arr[ind], dp, arr); 
            if (sub_res != INT_MAX)
                take = 1 + sub_res;
        }
        int ntake=f(ind-1,amount,dp,arr);

        dp[ind][amount]=min(take,ntake);
        return dp[ind][amount];
    }
};