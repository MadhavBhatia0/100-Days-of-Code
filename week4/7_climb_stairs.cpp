//LEETCODE 70. Climbing Stairs
class Solution {
public:
    int fibo(int n,vector<int>& dp)
    {
        if(n==0 || n==1)
        return 1;

        if(dp[n]!=-1) return dp[n];

        dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fibo(n,dp);
    }
};