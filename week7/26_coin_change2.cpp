//LEETCODE 518. Coin Change II
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int result=f(n-1,amount,dp,coins);
        return result;
    }
    int f(int ind,int amount,vector<vector<int>>& dp,vector<int>& arr){
        if(amount==0)
        return 1;

        if (ind < 0) 
        return 0;

        if(ind==0)
        {
            if(amount%arr[0]==0)
            return 1;
            else
            return 0;
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];

        int take = 0;
        if (arr[ind] <= amount) {
            take=f(ind, amount - arr[ind], dp, arr); 
        }
        int ntake=f(ind-1,amount,dp,arr);

        dp[ind][amount]=take+ntake;
        return dp[ind][amount];
    }
};