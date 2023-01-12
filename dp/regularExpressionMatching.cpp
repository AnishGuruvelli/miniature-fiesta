class Solution
{
public:
    bool isAllStars(string &p, int index2)
    {
        for (int i = 0; i <= index2; i++)
            if (p[i] != '*')
                return false;

        return true;
    }
    bool helper(string &s, string &p, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 && ind2 < 0)
            return true;
        if (ind2 < 0 && ind1 >= 0)
            return false;
        if (ind1 < 0 && ind2 >= 0)
            isAllStars(p, ind2);

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s[ind1] == p[ind2] || p[ind2] == '.')
            return dp[ind1][ind2] = helper(s, p, ind1 - 1, ind2 - 1, dp);

        else if (p[ind2] == '*')
            return dp[ind1][ind2] = helper(s, p, ind1 - 1, ind2, dp) ||
                                    helper(s, p, ind1, ind2 - 1, dp);

        return false;
    }
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(s, p, m - 1, n - 1, dp);
    }
};