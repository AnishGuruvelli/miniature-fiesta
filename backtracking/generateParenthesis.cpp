class Solution
{
public:
    vector<string> ans;

    void helper(int open, int close, int n, string current)
    {
        // 2*n = total : base case
        
        if (current.size() == 2 * n)
        {
            ans.push_back(current);
            return;
        }

        if (open < n)
            helper(open + 1, close, n, current + "(");
        if (close < open)
            helper(open, close + 1, n, current + ")");
    }

    vector<string> generateParenthesis(int n)
    {
        helper(0, 0, n, "");
        return ans;
    }
};