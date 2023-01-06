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