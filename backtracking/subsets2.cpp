class Solution
{
public:
    vector<vector<int>> ans;

    void subsets(vector<int> &nums, int ind, int n, vector<int> &output)
    {
        ans.push_back(output);

        for (int i = ind; i < n; i++)
        {
            output.push_back(nums[i]);
            subsets(nums, ind + 1, n, output);
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> output;
        subsets(nums, 0, nums.size(), output);
        sort(ans.begin(), ans.end());
        ans.erase(unique(begin(ans), end(ans)), end(ans));
        return ans;
    }
};