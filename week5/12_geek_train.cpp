// gfg Geek's Training
public:
  int helper(vector<vector<int>>& arr, int day,int last,vector<vector<int>>& dp)
  {
      if(day==0)
      {
          int maxi=0;
          for(int i=0;i<=2;i++)
          {
              if(i!=last)
              {
                  maxi=max(maxi,arr[0][i]);
              }
          }
          return maxi;
      }
      if(dp[day][last]!=-1)
      {
          return dp[day][last];
      }
      int maxi=0;
      for(int i=0;i<=2;i++)
      {
          if(i!=last)
          {
              maxi=max(arr[day][i]+helper(arr,day-1,i,dp),maxi);
          }
      }
      return dp[day][last]=maxi;
  }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return helper(arr,n-1,3,dp);
    }
// sc O(N*4)
// TC O(N)

//********************************************************************************
int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n,vector<int> (4,-1));
        
        dp[0][0]=max(arr[0][1],arr[0][2]);
        dp[0][1]=max(arr[0][0],arr[0][2]);
        dp[0][2]=max(arr[0][0],arr[0][1]);
        dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        for(int day=1;day<n;day++)
        {
            for(int last=0;last<=3;last++)
            {
                dp[day][last]=0;
                for(int task=0;task<3;task++)
                {
                    if(task!=last)
                    {
                        dp[day][last]=max(dp[day][last],(arr[day][task]+dp[day-1][task]));
                    }
                }
            }
            
        }
        
        return dp[n-1][3];
    }

// sc O(N*4)
// TC O(N) stack space not used