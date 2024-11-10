//LEETCODE 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1]&& nums[i]!=nums[j])
            {
                j++;
                swap(nums[i],nums[j]);
            }
        }
        return j+1;
    }
};
//SC O(1)
//TC O(N)