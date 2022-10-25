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

/*
class Solution
{
public:
    vector<vector<int>> ans;

    void permutations(vector<int> &nums, int n, int i)
    {
        if (n == i)
        {
            ans.push_back(nums);
        }

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
        return ans;
    }
};
* /