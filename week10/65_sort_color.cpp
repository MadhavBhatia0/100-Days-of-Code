//75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=0;
        int k=nums.size()-1;
        while(i<=k)
        {
            if(nums[i]==1){i++;
            continue;}
            else if(nums[i]==0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[k]);
                i--;
                k--;
            }
            i++;
        }
    }
};