//leetcode 1.TWO SUM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int secondele=target-nums[i];
            if(mpp.find(secondele)!=mpp.end())
            {
                ans.push_back(i);
                ans.push_back(mpp[secondele]);
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};
//TC O(NLOGN)
//SC O(N)

// if we have to return bool then use 2 pointer approach after sorting

string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}
