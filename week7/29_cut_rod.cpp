//gfg ROD CUTTING based on 0/1 knapsack
public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
    int f(int ind,int N,int price[],vector<vector<int>>& dp)
    {
        int rodlen=ind+1;
     if(ind==0)
     {
         if(rodlen<=N)
         {
             return price[0]*(N/rodlen);
         }
         else return 0;
     }
     if(dp[ind][N]!=-1)
     return dp[ind][N];
     
     int take=0;
     if(rodlen<=N)
     take=price[ind]+f(ind,N-rodlen,price,dp);
     int ntake=f(ind-1,N,price,dp);
     
     return dp[ind][N]=max(take,ntake);
    }