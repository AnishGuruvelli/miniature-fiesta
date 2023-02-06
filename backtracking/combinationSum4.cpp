// class Solution {
// public:
//     int noOfWays(vector<int> &nums, int target, int index, int size)
//     {
//         if(target < 0) return 0;
//         if(target == 0) return 1;

//         int ways = 0;
//         for(int i = 0; i<size; i++)
//             ways += noOfWays(nums, target - nums[i], i, size);
//         return ways;
//     }
//     int combinationSum4(vector<int>& nums, int target) {
//         return noOfWays(nums, target, 0, nums.size());
//     }
// };

class Solution {
public:
    int noOfWays(vector<int> &nums, int target, int size, vector<int> &dp)
    {
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];

        int ways = 0;
        for(int i = 0; i<size; i++)
            ways += noOfWays(nums, target - nums[i], size, dp);
        dp[target] = ways;
        return ways;
    }
    int combinationSum4(vector<int>& nums, int target) {

        vector<int> dp (target+1, -1);
        return noOfWays(nums, target, nums.size(), dp);
    }
};

// class Solution
// {
// public:
//     int combinationSum4(vector<int> &nums, int target)
//     {

//         vector<int> dp(target + 1, 0);
//         dp[0] = 1;
//         for (int i = 1; i <= target; i++)
//             for (int j = 0; j < nums.size(); j++)
//                 if (i - nums[j] >= 0)
//                     dp[i] += dp[i - nums[j]];
//         return dp[target];
//     }
// };