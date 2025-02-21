//LEETCODE 188. Best Time to Buy and Sell Stock IV
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> ahead(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++){
                if(buy)
                curr[buy][cap]=max(ahead[0][cap]-prices[ind],ahead[1][cap]);
                else{
                    curr[buy][cap]=max(ahead[1][cap-1]+prices[ind],ahead[0][cap]);
                }
                }
            }
            ahead=curr;
        }
        return ahead[1][k];
    }  
};
//SC O(2*(K+1)) DP ARRAY
//TC  O(N*2*(k+1))