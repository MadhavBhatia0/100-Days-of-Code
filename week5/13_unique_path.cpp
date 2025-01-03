// leetcode 62
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,(vector<int>(n,-1)));
        return f(m-1,n-1,dp);
    }
    int f(int i, int j,vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
        return 1;
        if(i<0 || j<0)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=(up+left);
    }
};
// SC=O(M*N)+O(M-1+N-1) +PATH LENGTH +DP
// TC=O(M*N) RECURSION

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                dp[0][0]=1;
                else{
                int up=0;
                int left=0;
                if(i>0)
                up=dp[i-1][j];
                if(j>0)
                left=dp[i][j-1];
                dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// SC=O(M*N) DP
// TC=O(M*N) RECURSION

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                temp[j]=1;
                else{
                    temp[j]=prev[j];
                    if(j>0)
                    temp[j]+=temp[j-1];
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
};
// SC=O(2N) temp,prev array
// TC=O(M*N) RECURSION