class Solution
{
public:
    int profit = 0;
    int helper(vector<int> &prices, int index, int buy, int n, vector<vector<int>> &dp)
    {
        // if it reached the last index then stop, even if it buys in the
        // beginning and does not sell, then profit will be -ve, as first we
        // are inserting -ve of first ele, so just return 0
        if (index == n)
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
            // which means we can now buy
            // or dont sell as of now, wait for a better price to sell,
            // so buy remains 0
            profit = max(
                (prices[index] + helper(prices, index + 1, 1, n, dp)),
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

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int minB = prices[0];
//         int maxP = 0;
//         for (int i = 0; i < prices.size(); i++)
//         {
//             if (minB > prices[i])
//             {
//                 minB = prices[i];
//             }
//             if (prices[i] - minB > 0)
//             {
//                 maxP += prices[i] - minB;
//                 minB = prices[i];
//             }
//         }
//         return maxP;
//     }
// };