class Solution
{
public:
    vector<vector<int>> ans;

    void permutations(vector<int> &nums, int n, int i)
    {
        if (n == i)
            ans.push_back(nums);

        for (int j = i; j < n; j++)
        {
            swap(nums[i], nums[j]);
            permutations(nums, n, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        permutations(nums, nums.size(), 0);
        sort(begin(ans), end(ans));
        ans.erase(unique(begin(ans), end(ans)), end(ans));
        return ans;
    }
};