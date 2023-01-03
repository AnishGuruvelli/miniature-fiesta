class Solution
{
public:
    int helper(vector<int> &prices, int n, int index, int buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if (n == index || cap == 0)
            return 0;

        int maxP = 0;

        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];

        if (buy)
        {
            maxP = max(
                (-prices[index] + helper(prices, n, index + 1, 0, cap, dp)),
                (0 + helper(prices, n, index + 1, 1, cap, dp)));
        }
        else
        {
            maxP = max(
                (prices[index] + helper(prices, n, index + 1, 1, cap - 1, dp)),
                (0 + helper(prices, n, index + 1, 0, cap, dp)));
        }

        // return maxP;
        return dp[index][buy][cap] = maxP;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        
        int capacity = 2;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // very important, it should be 3 over here, because no of transactions can be either 0, 1 or 2; for a total of 2 transactions.


        return helper(prices, n, 0, 1, capacity, dp);
    }
};

// this is wrong, not taking in account all the possibilites, for which we need recursion

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int minB=prices[0], maxP=0, count=0;
//         for(int i=0;i<prices.size();i++){
//             if(minB>prices[i]){
//                 minB=prices[i];
//             }

//             if(prices[i]-minB>0 && count<2){
//                 maxP+=prices[i]-minB;
//                 cout<<maxP<<endl;
//                 count++;
//             }
//         }
//         return maxP;
//     }
// };