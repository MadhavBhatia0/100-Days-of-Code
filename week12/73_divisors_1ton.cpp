//gfg Sum of all divisors from 1 to n
long long sumOfDivisors(int n) {
        // Write Your Code here
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    sum+=j;
                    if(i/j!=j)
                    sum+=(i/j);
                }
            }
        }
        return sum;
    }