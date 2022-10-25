class Solution
{
public:
    vector<vector<int>> ans;

    void backtrack(int start, int n, vector<int> nums, vector<int> comb)
    {
        ans.push_back(comb);

        for (int i = start; i < n; i++)
        {
            comb.push_back(nums[i]);
            backtrack(i + 1, n, nums, comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> comb;
        backtrack(0, nums.size(), nums, comb);
        return ans;
    }
};