// TIME LIMIT EXCEEDED: recursion appraoch :
// class Solution
// {
// public:
//     int helper(vector<int> &costs, int index, int n, int coins)
//     {
//         if (coins <= 0)
//             return 0;
//         if (index == n - 1)
//         {
//             if (costs[index] >= coins)
//                 return 0;
//             else
//                 return 1;
//         }
//         int buy = 0, notBuy;
//         if (costs[index] <= coins)
//             buy = 1 + helper(costs, index + 1, n, coins - costs[index]);

//         notBuy = 0 + helper(costs, index + 1, n, coins);

//         return max(buy, notBuy);
//     }
//     int maxIceCream(vector<int> &costs, int coins)
//     {
//         int n = costs.size();
//         sort(costs.begin(), costs.end());
//         return helper(costs, 0, n, coins);
//     }
// };

// brute force appraoch :

// class Solution
// {
// public:
//     int maxIceCream(vector<int> &costs, int coins)
//     {
//         int count = 0;
//         sort(costs.begin(), costs.end());
//         for (int i = 0; i < costs.size(); i++)
//         {
//             if (costs[i] > coins)
//                 break;
//             coins -= costs[i];
//             count++;
//         }
//         return count;
//     }
// };


// dp solution :

class Solution
{
public:
    int dfs(vector<int> &dp, vector<int> &nums, int coins, int i, int n)
    {
        if (coins <= 0)
            return 0;

        if (i == n - 1)
            if (nums[i] <= coins)
                return 1;
            else
                return 0;

        if (dp[i] != -1)
            return dp[i];

        int can = 0, cant = 0;

        if (nums[i] <= coins)
            can = 1 + dfs(dp, nums, coins - nums[i], i + 1, n);

        cant = dfs(dp, nums, coins, i + 1, n);
        return dp[i] = max(can, cant);
    }

    int maxIceCream(vector<int> &costs, int coins)
    {
        int n = costs.size();
        vector<int> dp(n + 1, -1);
        sort(costs.begin(), costs.end());
        return dfs(dp, costs, coins, 0, n);
    }
};