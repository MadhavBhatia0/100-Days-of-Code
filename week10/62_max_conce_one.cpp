//485. Max Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                count++;
                if(count>temp)
                temp=count;
            }
            else{
                count=0;
            }
        }
        return temp;
    }
};