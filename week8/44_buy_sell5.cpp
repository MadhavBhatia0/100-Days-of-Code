//309. Best Time to Buy and Sell Stock with Cooldown
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,dp,prices);
    }
    int f(int ind,int buy,vector<vector<int>>&dp,vector<int>& prices)
    {
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy)
        dp[ind][buy]=max(-prices[ind]+f(ind+1,0,dp,prices),f(ind+1,1,dp,prices));
        else
        dp[ind][buy]=max(prices[ind]+f(ind+2,1,dp,prices),f(ind+1,0,dp,prices));

        return dp[ind][buy];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                dp[ind][buy]=max(dp[ind+1][0]-prices[ind],dp[ind+1][1]);
                else{
                    dp[ind][buy]=max(dp[ind+2][1]+prices[ind],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2,0),ahead2(2,0),curr(2,0);

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                curr[buy]=max(ahead[0]-prices[ind],ahead[1]);
                else{
                    curr[buy]=max(ahead2[1]+prices[ind],ahead[0]);
                }
            }
            ahead2=ahead;
            ahead=curr;
        }
        return ahead[1];
    }
};