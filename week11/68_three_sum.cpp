//LEETCODE 15.3SUM

//ist approach is using three loops
//2nd is hashing
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> stt;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            set<int> st;
            for(int j=i+1;j<n;j++)
            {
                int third=-nums[i]-nums[j];
                if(st.find(third)!=st.end())
                {
                    vector<int> temp={nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    stt.insert(temp);
                }
                st.insert(nums[j]);
            }
        }
        
        vector<vector<int>> ans(stt.begin(),stt.end());
        return ans;
    }
};

//TC O(N*N + LOG(M)) 2 LOOPS+SET SEARCHING OF SIZE M WHICH IS VARIABLE
//SC O(N)+O(number of unique ans)*2 st will take max of n elements and EXTRA SPACE FOR ANS AND STT

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j=i+1;
            int k=n-1;
            while(k>j)
            {   int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++; k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        return ans;
    }
};
// TC O(N*N)
// SC O(no of unique ans)