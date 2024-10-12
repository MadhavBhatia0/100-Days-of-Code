int helper(vector<int>& height, int n, vector<int>& dp)
  {
      dp[0]=0;
      dp[1]=abs(height[1]-height[0]);
      
      for(int i=2;i<=n;i++)
      {
          int one=dp[i-1]+abs(height[i]-height[i-1]);
          int two=dp[i-2]+abs(height[i]-height[i-2]);
          dp[i]=min(one,two);
      }
      
      return dp[n];
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return helper(height,n-1,dp);
    }
// SC O(N)
// TC O(N)