class Solution
{
public:
    bool isAllStars(string &p, int ind2)
    {
        for (int i = 0; i <= ind2; i++)
            if (p[i] != '*')
                return false;

        return true;
    }
    bool solve(int ind1, int ind2, string &s, string &p, vector<vector<int>> &dp)
    {
        if (ind1 < 0 && ind2 < 0)
            return true;
        if (ind2 < 0)
            return false;
        if (ind1 < 0)
            return isAllStars(p, ind2);

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s[ind1] == p[ind2] || p[ind2] == '?')
            return dp[ind1][ind2] = solve(ind1 - 1, ind2 - 1, s, p, dp);

        else if (p[ind2] == '*')
            return dp[ind1][ind2] = solve(ind1 - 1, ind2, s, p, dp) ||
                                    solve(ind1, ind2 - 1, s, p, dp);

        return dp[ind1][ind2] = false;
    }
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, s, p, dp);
    }
};