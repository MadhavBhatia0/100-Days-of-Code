public:
  int helper(vector<int>& height, int n, vector<int>& dp)
  {
      if(n==0)
      return 0;
      
      if(dp[n]!=-1)
      return dp[n];
      
      int one=helper(height,n-1,dp)+abs(height[n]-height[n-1]);
      int two=INT_MAX;
      if(n>1)
      {
         two=helper(height,n-2,dp)+abs(height[n]-height[n-2]);
      }
      dp[n]=min(one,two);
      return min(one,two);
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return helper(height,n-1,dp);
    }
// SC O(N)
// TC O(N)