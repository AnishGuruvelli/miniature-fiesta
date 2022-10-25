class Solution
{
public:
    vector<vector<int>> ans;

    void helper(int n, int k, int index, vector<int> &output)
    {
        if (output.size() == k)
        {
            ans.push_back(output);
            return;
        }
        for (int i = index; i <= n; i++)
        {
            output.push_back(i);
            helper(n, k, i + 1, output);
            output.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> output;
        helper(n, k, 1, output);
        return ans;
    }
};
