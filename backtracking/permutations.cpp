class Solution
{
public:
    vector<vector<int>> ans;

    void permutation(vector<int> &nums, int i, int n)
    {

        if (i == n)
        {
            ans.push_back(ans);
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            permutation(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        permutation(nums, 0, nums.size() - 1);
        return ans;
    }
};