//LEETCODE 494. Target Sum
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        if ((totalSum - target) % 2 != 0 || (totalSum - target) < 0) {
            return 0;
        }

        int subsetSum = (totalSum - target) / 2;
        return countSubsets(nums, subsetSum);
    }

    int countSubsets(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        if (nums[0] <= target) {
            dp[0][nums[0]] = 1;
        }

        if (nums[0] == 0) {
            dp[0][0] = 2;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[i - 1][t];
                int take = (nums[i] <= t) ? dp[i - 1][t - nums[i]] : 0;

                dp[i][t] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }
};
