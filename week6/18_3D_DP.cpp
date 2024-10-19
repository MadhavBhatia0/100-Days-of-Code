// gfg chocolate pickup
//3D DP
int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,dp);
    }
    int f(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(j1<0 || j2<0 || j1>=grid[0].size()||j2>=grid[0].size())
        return INT_MIN;
        
        if(i==(grid.size()-1))
        {
            if(j1==j2)
            {
                return grid[i][j2];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        int maxi=INT_MIN;
        for(int k=-1;k<2;k++)
        {
            for(int j=-1;j<2;j++)
            {
                int value=0;
                if(j1==j2)
                {
                    value=grid[i][j2];
                }
                else{
                    value=grid[i][j2]+grid[i][j1];
                }
                maxi=max(maxi,(f(i+1,j1+k,j2+j,grid,dp)+value));
            }
        }
        dp[i][j1][j2]=maxi;
        return dp[i][j1][j2];
    }
// SPACE N*M*M(DP ARRAY) + O(N) RECURSION
//TIME 3*3*N*M*M NUMBER OF STATES