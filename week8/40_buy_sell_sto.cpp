//LEETCODE 121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max(ans,prices[j]-prices[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int b=prices[0];
        for(int i=1;i<n;i++)
        {
            if(b>prices[i])
            {
                b=prices[i];
            }
            else{
                ans=max(ans,prices[i]-b);
            }
        }
        return ans;
    }
};