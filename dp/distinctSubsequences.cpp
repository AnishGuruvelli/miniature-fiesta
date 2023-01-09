class Solution
{
public:
    int helper(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
    {
        if (n < 0)
            return 1;
        if (m < 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        int x, y;
        if (s1[m] == s2[n])
        {
            x = helper(s1, s2, m - 1, n, dp);
            y = helper(s1, s2, m - 1, n - 1, dp);

            return dp[m][n] = x + y;
        }
        else
            return dp[m][n] = helper(s1, s2, m - 1, n, dp);
            
    }
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(s, t, m - 1, n - 1, dp);
    }
};
