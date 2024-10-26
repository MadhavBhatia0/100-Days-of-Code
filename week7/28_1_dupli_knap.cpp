//0/1 kanpsack with duplicate items
int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return f(N-1,W,val,wt,dp);
    }
    int f(int ind,int W,int val[],int wt[],vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            if(wt[0]<=W)
            {
                return val[0]*(W/wt[0]);
            }
            else
            return 0;
        }
        if(W==0)
        return 0;
        if(dp[ind][W]!=-1)
        return dp[ind][W];
        
        int take=0;
        if(wt[ind]<=W)
        take=val[ind]+f(ind,W-wt[ind],val,wt,dp);
        int ntake=f(ind-1,W,val,wt,dp);
        
        return dp[ind][W]=max(take,ntake);
    }