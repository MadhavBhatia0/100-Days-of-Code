//leetcode 714. Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return max(f(0,1,dp,prices,fee),0);
    }
    int f(int ind,int buy,vector<vector<int>>&dp,vector<int>& prices,int fee)
    {
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy)
        dp[ind][buy]=max(-prices[ind]+f(ind+1,0,dp,prices,fee),f(ind+1,1,dp,prices,fee));
        else
        dp[ind][buy]=max(prices[ind]-fee+f(ind+1,1,dp,prices,fee),f(ind+1,0,dp,prices,fee));

        return dp[ind][buy];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                else
                dp[ind][buy]=max(prices[ind]-fee+dp[ind+1][1],dp[ind+1][0]);
            }
        }

        return dp[0][1];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>ahead(2,0),curr(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                curr[buy]=max(-prices[ind]+ahead[0],ahead[1]);
                else
                curr[buy]=max(prices[ind]-fee+ahead[1],ahead[0]);
            }
            ahead=curr;
        }

        return ahead[1];
    }
};