class Solution
{
public:
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> v1(nums.begin(), nums.end() - 1);
        vector<int> v2(nums.begin() + 1, nums.end());
        return max(solve(v1), solve(v2));
    }
};