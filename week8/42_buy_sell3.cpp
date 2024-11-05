//LEETCODE 123. Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,dp,prices);

    }
    int f(int ind,int buy,int cap,vector<vector<vector<int>>>&dp,vector<int>& p)
    {
        if(cap==0) return 0;
        if(ind==p.size())
        return 0;

        if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];

        int profit=0;
        if(buy)
        profit=max(f(ind+1,0,cap,dp,p)-p[ind],f(ind+1,1,cap,dp,p));
        else{
            profit=max(f(ind+1,1,cap-1,dp,p)+p[ind],f(ind+1,0,cap,dp,p));
        }
        return dp[ind][buy][cap]=profit;
    }
};
//sc O(N)+O(N*2*3) STACK+DP ARRAY
//TC  O(N*2*3)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++){
                if(buy)
                dp[ind][buy][cap]=max(dp[ind+1][0][cap]-prices[ind],dp[ind+1][1][cap]);
                else{
                    dp[ind][buy][cap]=max(dp[ind+1][1][cap-1]+prices[ind],dp[ind+1][0][cap]);
                }
                }
            }
        }
        return dp[0][1][2];
    }
};
//sc O(N*2*3) DP ARRAY
//TC  O(N*2*3)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> ahead(2,vector<int>(3,0)),curr(2,vector<int>(3,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++){
                if(buy)
                curr[buy][cap]=max(ahead[0][cap]-prices[ind],ahead[1][cap]);
                else{
                    curr[buy][cap]=max(ahead[1][cap-1]+prices[ind],ahead[0][cap]);
                }
                }
            }
            ahead=curr;
        }
        return ahead[1][2];
    }
};
//SC O(2*3) DP ARRAY
//TC  O(N*2*3)