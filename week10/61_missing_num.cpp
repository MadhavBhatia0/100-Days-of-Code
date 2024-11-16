//LEETCODE 268. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*n+n)/2;
        int summ=0;
        for(int i=0;i<n;i++)
        {
            summ+=nums[i];
        }return (sum-summ);
    }
}; //we may not be able to store sum for large n so xor solution is better


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans^i^nums[i];
        }
        return ans^n;
    }
};