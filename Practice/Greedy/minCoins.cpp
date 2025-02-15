//gfg
//dp
int minCoins(vector<int> &coins, int sum) {
    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= sum; i++) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[sum] == INT_MAX ? -1 : dp[sum];
}
// using greedy passes 120/1111 test cases
class Solution {

    public:
    static bool comp(int a,int b)
    {
        if(b<a) return 1;
        return 0;
    }
      int minCoins(vector<int> &coins, int sum) {
          // Your code goes here
          int i=0;        
          sort(coins.begin(),coins.end(),comp);
          return helper(coins,i,sum);
      }
      int helper(vector<int> &coins,int i,int sum) {
          if(sum==0) return 0;
          if(coins.size()==i) return -1;
          
          if(sum>=coins[i])
          {
              int take=helper(coins,i,sum-coins[i]);
              int ntake=helper(coins,i+1,sum);
              if(take==-1 && ntake==-1) return -1;
              if(take!=-1 && ntake!=-1)
              {
                  return min(take+1,ntake);
              }
              if(ntake==-1) { return take+1;} 
              else 
              return ntake;
          }
          return helper(coins,i+1,sum);
      }
  
  };