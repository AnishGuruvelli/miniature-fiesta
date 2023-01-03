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

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // minB is minimum price to buy and maxP is max profit one can make doing this
        int n = prices.size();
        int minB = prices[0], maxP = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            minB = min(minB, prices[i]);
            maxP = max(maxP, prices[i] - minB);
        }
        return maxP;
    }
};
