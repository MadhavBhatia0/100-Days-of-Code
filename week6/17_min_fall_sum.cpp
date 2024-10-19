class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,(vector<int>(n,INT_MAX)));
        int temp=INT_MAX;
        for(int i=0;i<n;i++)
        {
            temp=min(temp,f(m-1,i,dp,matrix));
        }
        return temp;
    }
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& matrix)
    {
        if(i<0 || j<0 || i>=matrix.size()|| j>=matrix[0].size())
        return INT_MAX;

        if(i==0)
        return matrix[i][j];

        if(dp[i][j]!=INT_MAX)
        return dp[i][j];

        int up=INT_MAX,upleft=INT_MAX,upright=INT_MAX;
        if(i>0)
        {
            up=f(i-1,j,dp,matrix);
            if(j>0)
            {
                upleft=f(i-1,j-1,dp,matrix);
            }
            upright=f(i-1,j+1,dp,matrix);
        }
        dp[i][j]=min(up,min(upleft,upright))+matrix[i][j];
        return dp[i][j];
    }
};