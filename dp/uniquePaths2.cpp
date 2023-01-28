class Solution
{
public:
    int helper(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &dp)
    {
        if (!i && !j)
            return 1;
        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = helper(obstacleGrid, i - 1, j, dp) + helper(obstacleGrid, i, j - 1, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0])
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(obstacleGrid, m - 1, n - 1, dp);
    }
};

// // TLE
// class Solution
// {
// public:
//     int solve(vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid, int i, int j, int m, int n)
//     {
//         if (i == m && j == n)
//             return 1;
//         if (i > m || j > n)
//             return 0;
//         if (obstacleGrid[i][j] == 1)
//             return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];
//         return solve(dp, obstacleGrid, i + 1, j, m, n) + solve(dp, obstacleGrid, i, j + 1, m, n);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
//     {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
//             return 0;

//         // [[0]]
//         if(m==1 && n==1 && obstacleGrid[m-1][n-1]==0) return 1;

//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solve(dp, obstacleGrid, 0, 0, m-1, n-1);
//     }
// };