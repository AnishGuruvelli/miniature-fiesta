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

/*
#We are "NOT SURE" if subtracting 1 or 4 or 9 or 16 first would be optimal as we don't know the future results
#So whenever you are not sure which step would be optimal, no need to stress on guessing the optimal one just =>
"TRY ALL OPTIONS, THEN CHOOSE THE OPTIMAL ONE"
#So for any given target, just try all the perfect squares you can subtract

target(18) => [18 - (1^2) = 17] =>target(17)
target(18) => [18 - (2^2) = 14] => target(14)
target(18) => [18 - (3^2) = 9] => target(9)
target(18) => [18 - (4^2) = 2] => target(2)
            

#Now we have a smaller subproblem, which could be solved using recursion
#so
for target(18) = 1 + min (target(17), target(14), target(9), target(2))
*/