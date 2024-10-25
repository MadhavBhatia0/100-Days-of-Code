//GFG 0/1 KNAPSACK
int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return f(n-1,W,val,wt,dp);
    }
    int f(int ind,int W,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            if(wt[0]<=W)
            return val[0];
            else
            return 0;
        }
        if(W==0)
        return 0;
        if(dp[ind][W]!=-1)
        return dp[ind][W];
        
        int take=0;
        if(wt[ind]<=W)
        take=val[ind]+f(ind-1,W-wt[ind],val,wt,dp);
        int ntake=f(ind-1,W,val,wt,dp);
        
        return dp[ind][W]=max(take,ntake);
    }