int helper(int k, vector<int>& arr,vector<int>& dp,int n)
  {
      if(n==0)
      return 0;
      
      if(dp[n]!=-1)
      return dp[n];
      
      int temp=INT_MAX;
      for(int i=1;i<=k;i++)
      {
          if(i<=n)
          temp= min(helper(k,arr,dp,n-i)+abs(arr[n]-arr[n-i]),temp);
      }
      dp[n]=temp;
      return dp[n];
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,-1);
        return helper(k,arr,dp,n-1);
    }
// SC STACK+DP =O(N)
// TC for every junction loop is run k times= O(N*K)