class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &output, int k, int n, int index, int sum, int size)
    {
        if (k == size && sum == n)
        {
            ans.push_back(output);
            return;
        }
        else if (size > k || sum > n)
            return;

        for (int i = index; i <= 9; i++)
        {
            sum += i;
            output.push_back(i);
            solve(output, k, n, i + 1, sum, size + 1);
            sum -= i;
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> output;
        solve(output, k, n, 1, 0, 0);
        return ans;
    }
};
