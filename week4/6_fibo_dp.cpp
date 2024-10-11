public:
  const int MOD = 1e9 + 7;
   long long int fibo(int n,vector<long long int>& dp) 
   {
       if(n<0)
       return 0;
        if(n<=1)
        return n;
        
        if(dp[n]!=-1)
        return dp[n];
        
        dp[n] = (fibo(n - 1, dp) + fibo(n - 2, dp)) % MOD;
        return dp[n];
   }
    long long int topDown(int n) {
        // code here
        // sc=O(N); RECURSION STACK + ARRAY
        // tc=O(N);
        vector<long long int> dp(n + 1, -1);
        return fibo(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
        if(n<0)
        return 0;
        if(n<=1)
        return n;
        
        int prev=1;
        int prev2=0;
        for(int i=2;i<=n;i++)
        {
            long long int curr = (prev + prev2) % MOD;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }// sc=O(1);
     // tc=O(N);