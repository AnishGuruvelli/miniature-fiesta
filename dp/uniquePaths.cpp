class Solution
{
public:
    int helper(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == (n - 1) && j == (m - 1))
            return 1;
        if (i >= n || j >= m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        else
            return dp[i][j] = helper(i + 1, j, n, m, dp) + helper(i, j + 1, n, m, dp);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(0, 0, n, m, dp);
    }
};

// brute force: recursion:
// class Solution
// {
// public:
//     int helper(int i, int j, int n, int m)
//     {
//         if (i == (n - 1) && j == (m - 1))
//             return 1;
//         if (i >= n || j >= m)
//             return 0;
//         else
//             return helper(i + 1, j, n, m) + helper(i, j + 1, n, m);
//     }
//     int uniquePaths(int m, int n)
//     {
//         return helper(0, 0, n, m);
//     }
// };

// class Solution
// {
// public:
//     int uniquePaths(int m, int n)
//     {
//         vector<vector<int>> dp(m, vector<int>(n, 1));
//         for (int i = 1; i < m; i++)
//         {
//             for (int j = 1; j < n; j++)
//             {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };