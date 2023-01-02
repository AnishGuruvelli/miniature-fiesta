// https://www.youtube.com/watch?v=20dbrEfB8-A

class Solution
{
public:
    int numTilings(int n)
    {
        vector<long long> dp(n + 5, 0);
        long long mod = 1000000007;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = 2 * dp[i - 1] + dp[i - 3];
            dp[i] %= mod;
        }
        return dp[n];
    }
};