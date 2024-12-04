//Leetcode 204. Count Primes
class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        int prime[n];
        int count=0;
        for(int i=0;i<n;i++) prime[i]=1;

        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==1)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    prime[j]=0;
                }
            }
        }
        for(int i=2;i<n;i++)
        {
            if(prime[i]) count++;
        }
        return count;
    }
};