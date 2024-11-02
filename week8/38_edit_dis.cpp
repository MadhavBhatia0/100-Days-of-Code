//LEETCODE 72. Edit Distance
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,word1,word2);
    }
    int f(int i,int j,vector<vector<int>>&dp,string s1, string s2)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s1[i]==s2[j])
        return dp[i][j]=f(i-1,j-1,dp,s1,s2);
        int insert=1+f(i,j-1,dp,s1,s2);
        int del=1+f(i-1,j,dp,s1,s2);
        int repl=1+f(i-1,j-1,dp,s1,s2);
        return dp[i][j]=min(insert,min(del,repl));
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=0;i<=m;i++) dp[0][i]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int repl=1+dp[i-1][j-1];
                    dp[i][j]=min(insert,min(del,repl));
                }
            }
        }

        return dp[n][m];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=0;i<=m;i++) prev[i]=i;
        for(int i=1;i<=n;i++)
        {
            curr[0] = i;
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                curr[j]=prev[j-1];
                else{
                    int insert=1+curr[j-1];
                    int del=1+prev[j];
                    int repl=1+prev[j-1];
                    curr[j]=min(insert,min(del,repl));
                }
            }
            prev=curr;
        }

        return prev[m];
    }
};
