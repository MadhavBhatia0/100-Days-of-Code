//CN
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.

	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool take = false;
                if (target >= arr[ind]) {
                    take = dp[ind - 1][target-arr[ind]];
                }
                    bool ntake=dp[ind-1][target];
                    dp[ind][target]=(take || ntake);
            }
        }
		int mini=sum;
        
        for(int i=0;i<=sum;i++)
        {
            if(dp[n-1][i]==1)
            {
                int s=i;
                int s2=sum-i;
                mini=min(mini,abs(s-s2));
            }
        }
        return mini;
}
