//LEETCODE 2149
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int> rearranged(nums.size()); // Create a new vector for rearranged elements
        int positiveIndex = 0; // Initialize index for placing positive numbers, starting from position 0
        int negativeIndex = 1; // Initialize index for placing negative numbers, starting from position 1

        // Iterate over each number in the input array
        for (int num : nums) {
            if (num > 0) {
                // If current number is positive, place it at the next available positive index
                rearranged[positiveIndex] = num;
                positiveIndex += 2; // Increment the position by 2 to skip the next negative place
            } else {
                // If current number is negative, place it at the next available negative index
                rearranged[negativeIndex] = num;
                negativeIndex += 2; // Increment the position by 2 to skip the next positive place
            }
        }
        // Return the rearranged vector
        return rearranged;
    }
};