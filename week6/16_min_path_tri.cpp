//leetcode 120
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,(vector<int>(n,-1)));
        int temp=INT_MAX;
        for(int i=0;i<n;i++)
        {
            temp=min(temp,f(m-1,i,dp,triangle));
        }
        return temp;
    }
    int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& triangle)
    {
        if(i==0&&j==0)
        return triangle[i][j];
        if(i<0 || j<0 || triangle[i].size()<=j)
        return INT_MAX;
        
        if(dp[i][j]!=-1)
        return dp[i][j];

        int up=INT_MAX;
        int upleft=INT_MAX;

        if(i>0)
        {
            up=f(i-1,j,dp,triangle);
            if(j>0)
            {
                upleft=f(i-1,j-1,dp,triangle);
            }
        }
        dp[i][j]=min(up,upleft)+triangle[i][j];
        return dp[i][j];
    }
};
//