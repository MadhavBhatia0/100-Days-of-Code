//LEETCODE 1752. Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>arr[(i+1)%n])
            {
                count++;
                if(count>=2)
                return false;
            }
        }
        return true;
    }
};
//TC O(N+1)
//SC O(N)