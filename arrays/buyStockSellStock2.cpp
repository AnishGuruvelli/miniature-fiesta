class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minB = prices[0];
        int maxP = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (minB > prices[i])
            {
                minB = prices[i];
            }
            if (prices[i] - minB > 0)
            {
                maxP += prices[i] - minB;
                minB = prices[i];
            }
        }
        return maxP;
    }
};