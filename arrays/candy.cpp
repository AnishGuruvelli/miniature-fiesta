class Solution
{
public:
    int candy(vector<int> &A)
    {
        int n = A.size();

        vector<int> ans(n, 1);

        // traversing from left to right
        for (int i = 1; i < n; i++)
            if (A[i] > A[i - 1])
                ans[i] = ans[i - 1] + 1;

        // ex: 1 0 2
        // 1 1 2

        // traversing from right to left
        for (int i = n - 1; i >= 1; i--)
            if (A[i - 1] > A[i])
                ans[i - 1] = max(ans[i] + 1, ans[i - 1]);
        
        // ex: 1 0 2
        // 1 1 2
        // 2 1 2

        int sum = 0;

        for (auto i: ans)
            sum += i;

        return sum;
    }
};
