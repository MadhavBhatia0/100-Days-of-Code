//115. Distinct Subsequences
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,s,t);
    }
    int f(int i,int j,vector<vector<int>>& dp,string s, string t)
    {
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==t[j])
        return dp[i][j]=f(i-1,j-1,dp,s,t)+f(i-1,j,dp,s,t);
        else
        return f(i-1,j,dp,s,t);
    }
};
//TC O(N*M)
//SC O(N*M)+O(N+M)

//using tabulation
//double is used because of some test case error
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                dp[i][j]= dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};
//TC O(N*M)
//SC O(N*M)

//PACE OPTIMIZED
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> prev(m+1,0),curr(m+1,0);
        prev[0]=1;
        curr[0]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                curr[j]=prev[j-1]+prev[j];
                else
                curr[j]= prev[j];
            }
            prev=curr;
        }
        return (int)prev[m];
    }
};
//TC O(N*M)
//SC O(2*M)

// 1d array optimized
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> prev(m+1,0);
        prev[0]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                if(s[i-1]==t[j-1])
                prev[j]=prev[j-1]+prev[j];
            }
        }
        return (int)prev[m];
    }
};
//TC O(N*M)
//SC O(M)