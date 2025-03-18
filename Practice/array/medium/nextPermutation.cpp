//lc 31. Next Permutation
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int ind=-1;
            int n=nums.size();
            for(int i=n-2;i>ind;i--)
            {
                if(nums[i]<nums[i+1])
                {
                    ind=i;
                    break;
                }
            }
            if(ind==-1)
            {
                reverse(nums,0,n-1);
                return;
            }
            
            for(int i=n-1;i>ind;i--)
            {
                if(nums[i]>nums[ind])
                {
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            reverse(nums,ind+1,n-1);
            return;
        }
        void reverse(vector<int>& nums, int l, int r) {
        while (l < r){
          swap(nums[l], nums[r]);
          l++;
          r--;
        }
        }
    };
// Time Complexity: O(n)
// Space Complexity: O(1)