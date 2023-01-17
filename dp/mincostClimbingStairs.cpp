class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        // min of previous two steps + current step's cost.
        for (int i = 2; i < n; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];

        return min(dp[n - 1], dp[n - 2]);
        // return the min of last two steps.
    }
};
