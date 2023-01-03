class Solution
{
public:
    int helper(int index, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (n == index || cap == 0)
            return 0;

        int maxP = 0;

        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];

        if (buy)
        {
            maxP = max(
                (-prices[index] + helper(index + 1, 0, cap, n, prices, dp)),
                (0 + helper(index + 1, 1, cap, n, prices, dp)));
        }

        else
        {
            maxP = max(
                (prices[index] + helper(index + 1, 1, cap - 1, n, prices, dp)),
                (0 + helper(index + 1, 0, cap, n, prices, dp)));
        }

        // return maxP;
        return dp[index][buy][cap] = maxP;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        // very important, it should be k+1 over here, because no of transactions can be either 0, 1, 2 .... until k

        return helper(0, 1, k, n, prices, dp);
    }
};