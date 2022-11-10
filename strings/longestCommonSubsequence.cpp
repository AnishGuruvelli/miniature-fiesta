/// TABULATION

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// SPACE OPTIMIZATION FOR TABULATION:

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0));
    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m];
}

/// OR THIS : MEMOIZATION

#include <bits/stdc++.h>
int helper(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (str1[i] == str2[j])
    {
        return dp[i][j] = 1 + helper(i - 1, j - 1, str1, str2, dp);
    }
    int ans1 = helper(i - 1, j, str1, str2, dp);
    int ans2 = helper(i, j - 1, str1, str2, dp);
    int finalans = max(ans1, ans2);
    dp[i][j] = finalans;
    return dp[i][j];
}
int lcs(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = helper(n - 1, m - 1, str1, str2);
}

/// leetcode : https://leetcode.com/problems/longest-common-subsequence/description/

class Solution
{
public:
    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
        {
            return dp[i][j] = 1 + helper(s1, s2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(helper(s1, s2, i - 1, j, dp), helper(s1, s2, i, j - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(text1, text2, m - 1, n - 1, dp);
    }
};

/// BRUTE FORCE APPROACH

class Solution
{
public:
    int helper(string s1, string s2, int m, int n)
    {

        if (m == 0 || n == 0)
            return 0;

        if (s1[m - 1] == s2[n - 1])
        {
            return 1 + helper(s1, s2, m - 1, n - 1);
        }
        else
        {
            return max(helper(s1, s2, m - 1, n), helper(s1, s2, m, n - 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        int ans = helper(text1, text2, m, n);
        return ans;
    }
};