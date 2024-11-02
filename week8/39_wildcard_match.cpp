//LEETCODE 44. Wildcard Matching
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); 
        return f(n - 1, m - 1, dp, p, s);
    }
    bool f(int i,int j,vector<vector<int>>& dp,string s1, string s2)
    {
        if(i<0 && j<0)
        return true;

        if(i<0&&j>=0)
        return false;

        if(j<0 && i>=0)
        {
            for(int k=0;k<=i;k++)
            {
                if(s1[k]!='*')
                return false;
            }
            return true;
        }

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s1[i]==s2[j] || s1[i]=='?')
        {
            return dp[i][j]=f(i-1,j-1,dp,s1,s2);
        }
        if(s1[i]=='*')
        return dp[i][j]=f(i-1,j,dp,s1,s2) ||f(i,j-1,dp,s1,s2);

        return dp[i][j] = false;
    }
};