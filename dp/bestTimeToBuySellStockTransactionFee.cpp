class Solution
{
public:
    int profit = 0;
    int helper(vector<int> &prices, int index, int buy, int n, int fee, vector<vector<int>> &dp)
    {
        if (index == n)
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        if (buy)
        {
            profit = max(
                (-prices[index] + helper(prices, index + 1, 0, n, fee, dp)),
                (0 + helper(prices, index + 1, 1, n, fee, dp)));
        }

        else
        {
            // just deduct fee from the profit once, after the sell operation is done
            profit = max(
                (prices[index] - fee + helper(prices, index + 1, 1, n, fee, dp)),
                (0 + helper(prices, index + 1, 0, n, fee, dp)));
        }

        // return profit;
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 1, n, fee, dp);
    }
};
