// leetcode 1143. Longest Common Subsequence
// using memo
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,text1,text2);
    }
    int f(int ind1,int ind2,vector<vector<int>>& dp,string s1, string s2)
    {
        if(ind1<0 || ind2<0)
        return 0;

        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2])
        dp[ind1][ind2]=1+f(ind1-1,ind2-1,dp,s1,s2);
        else{
            dp[ind1][ind2]=max(f(ind1-1,ind2,dp,s1,s2),f(ind1,ind2-1,dp,s1,s2));
        }

        return dp[ind1][ind2];
    }
};
//TC O(N*M)
//SC O(N*M)+O(N+M) DP+STACK

//MEMO INDEX SHIFTED
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,dp,text1,text2);
    }
    int f(int ind1,int ind2,vector<vector<int>>& dp,string s1, string s2)
    {
        if(ind1==0 || ind2==0)
        return 0;

        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];

        if(s1[ind1-1]==s2[ind2-1])
        dp[ind1][ind2]=1+f(ind1-1,ind2-1,dp,s1,s2);
        else{
            dp[ind1][ind2]=max(f(ind1-1,ind2,dp,s1,s2),f(ind1,ind2-1,dp,s1,s2));
        }

        return dp[ind1][ind2];
    }
};
//TABULATION
//TC O(N*M) TWO LOOPS
// SC(N*M) DP ARRAY
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
// SPACE OPTIMIZED TO O(2*(M+1))
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0),curr(m+1,0);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                curr[j]=1+prev[j-1];
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};