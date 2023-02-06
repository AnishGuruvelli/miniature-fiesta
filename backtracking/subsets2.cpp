class Solution
{
public:
    set<vector<int>> ans;

    void subsets(vector<int> &nums, int ind, int n, vector<int> &output)
    {
        ans.insert(output);

        for (int i = ind; i < n; i++)
        {
            output.push_back(nums[i]);
            subsets(nums, i + 1, n, output);
            // imp its i+1, not ind+1
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> output;
        sort(nums.begin(), nums.end());
        subsets(nums, 0, nums.size(), output);
        // ans.erase(unique(begin(ans), end(ans)), end(ans));

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};