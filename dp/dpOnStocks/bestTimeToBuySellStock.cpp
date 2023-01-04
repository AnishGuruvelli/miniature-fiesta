class Solution
{
public:
    int helper(vector<int> &prices, int index, int n, int buy, int noOfTransactions, vector<vector<int>> &dp)
    {
        if (index == n || noOfTransactions <= 0)
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        if (buy)
        {
            profit = max(
                (-prices[index] + helper(prices, index + 1, n, 0, noOfTransactions, dp)),
                (0 + helper(prices, index + 1, n, 1, noOfTransactions, dp)));
        }
        else
        {
            profit = max(
                (prices[index] + helper(prices, index + 1, n, 0, noOfTransactions - 1, dp)),
                (0 + helper(prices, index + 1, n, 0, noOfTransactions, dp)));
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, n, 1, 1, dp);
    }
};

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int n = prices.size();
//         int maxProfit = 0;
//         int buy = prices[0];
//         for (int i = 1; i < n; i++)
//         {
//             if (buy > prices[i])
//             {
//                 buy = prices[i];
//             }
//             if (prices[i] - buy > maxProfit)
//             {
//                 maxProfit = prices[i] - buy;
//             }
//         }
//         return maxProfit;
//     }
// };

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         // minB is minimum price to buy and maxP is max profit one can make doing this
//         int n = prices.size();
//         int minB = prices[0], maxP = INT_MIN;

//         for (int i = 0; i < n; i++)
//         {
//             minB = min(minB, prices[i]);
//             maxP = max(maxP, prices[i] - minB);
//         }
//         return maxP;
//     }
// };
