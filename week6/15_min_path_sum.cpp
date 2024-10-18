//leetcode 64
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
    }
    int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>>&grid)
    {
        if(i==0 && j==0)
        return grid[0][0];

        if(i<0||j<0)
        return INT_MAX;

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=INT_MAX;
        int left=INT_MAX;

        if(i>0)
        up=f(i-1,j,dp,grid);
        if(j>0)
        left=f(i,j-1,dp,grid);

        dp[i][j]=min(up,left)+grid[i][j];
        return dp[i][j];
    }
};

//**************************************** */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                } else {
                    int up = INT_MAX;
                    int left = INT_MAX;

                    if (i > 0)
                        up = dp[i-1][j];
                    if (j > 0)
                        left = dp[i][j-1];
                    dp[i][j]=min(up,left)+grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};