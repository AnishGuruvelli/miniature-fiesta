class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int result = INT_MAX;
        for (int i = 1; i <= sqrt(n); i++)
        {
            int a = i * i;
            int curr = n - a;
            int b = 1 + solve(curr, dp);
            result = min(result, b);
        }
        return dp[n] = result;
        // return result;
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};