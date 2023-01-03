class Solution
{
public:
    int profit = 0;
    int helper(vector<int> &prices, int index, int buy, int n, vector<vector<int>> &dp)
    {
        // if it is greater than n, *its not index == n* ,
        // cuz when we are doing index+2 in the sell operation, then it will go out of bounds

        if (index >= n)
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        // if we want to buy
        // if (buy == 1)
        if (buy)
        {
            // if buying then first step: making buy=0, cuz cant buy anymore, have to sell
            // have to insert first ele as negative, cuz during profit,
            // we deduct from the selling price directly
            // if not buying then dont add anything, and also keep buy as 1 only.
            profit = max(
                (-prices[index] + helper(prices, index + 1, 0, n, dp)),
                (0 + helper(prices, index + 1, 1, n, dp)));
        }

        // if we want to sell
        else
        {
            // 2 options we have again, either sell now, so buy becomes 1 again,
            // which means we can now buy && do index+2, cuz we cant buy on the immediate next day
            // or dont sell as of now, wait for a better price to sell,
            // so buy remains 0
            profit = max(
                (prices[index] + helper(prices, index + 2, 1, n, dp)),
                (0 + helper(prices, index + 1, 0, n, dp)));
        }

        // return profit;
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 1, n, dp);
    }
};