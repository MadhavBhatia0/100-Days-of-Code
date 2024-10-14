int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int temp=INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0)
                temp=min(temp,(dp[i-j]+abs(arr[i]-arr[i-j])));
            }
            dp[i]=temp;
        }
        return dp[n-1];
    }
// SC DP =O(N)
// TC for every junction loop is run k times= O(N*K)
// space could be optimized if we could get last k values
// worst case k=N so again the sc will be O(N)