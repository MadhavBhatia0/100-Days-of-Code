//509. Fibonacci Number
class Solution {
public:
    int fib(int n) {
        if(n==1)
        return 1;
        if(n==0)
        return 0;
        return fib(n-1)+fib(n-2);
    }
};
//TC=O(2^N) 2 calls
//SC=O(N)   recursive stack, maximum depth in N

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
        return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//TC=O(N)
//SC=O(N)

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
        return n;
        int prev=0;
        int prev2=1;
        for(int i=2;i<=n;i++)
        {
            int curr=prev2+prev;
            prev=prev2;
            prev2=curr;
        }
        return prev2;
    }
};
//TC=O(N)
//SC=O(1)