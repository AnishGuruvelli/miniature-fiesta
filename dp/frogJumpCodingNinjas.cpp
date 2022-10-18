// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>

int helper(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int left = helper(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);

    int right = INT_MAX;

    if (index > 1)
    {
        right = helper(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
    }

    return dp[index] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    helper(n - 1, heights, dp);
}

/*

PLAIN RECURSION; NOW DO DP

#include <bits/stdc++.h>

int helper(int index, vector<int> &heights)
{
    if (index == 0)
        return 0;

    int left = helper(index - 1, heights) + abs(heights[index] - heights[index - 1]);

    int right = INT_MAX;

    if (index > 1)
    {
        right = helper(index - 2, heights) + abs(heights[index] - heights[index - 2]);
    }

    return min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    helper(n - 1, heights);
}
*/

#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev2 = 0;
    int prev = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = prev2 + abs(heights[i] - heights[i - 2]);
        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

#include <bits/stdc++.h>

int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 1)
        return 0;
    if (dp[n - 1] != -1)
        return dp[n - 1];
    int ans = solve(n - 1, heights, dp) + abs(heights[n - 1] - heights[n - 2]);
    if (n > 2)
        ans = min(ans,
                  solve(n - 2, heights, dp) + abs(heights[n - 1] - heights[n - 3]));
    return dp[n - 1] = ans;
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(n, heights, dp);
}