//gfg subset sum
bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
    }
    bool f(int ind,int target,vector<int>& arr,vector<vector<int>>& dp)
    {
        if(target==0)
        return 1;
        
        if(ind==0)
        return (arr[0]==target);
        
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        
        bool take = false;
    if (target >= arr[ind]) {
        take = f(ind - 1, target - arr[ind], arr, dp);
    }
        bool ntake=f(ind-1,target,arr,dp);
        return dp[ind][target]=(take || ntake);
    }
//O(N*TARGET) TC
//O(N*TARGET)+O(N) SC


public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n=arr.size();
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
        
        return dp[n-1][sum];
}
//O(N*TARGET) TC
//O(N*TARGET) SC