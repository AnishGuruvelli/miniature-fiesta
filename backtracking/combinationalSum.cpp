// https://www.youtube.com/watch?v=OyZFFqQtu98

class Solution
{
public:
    void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (index == arr.size())
        {
            if (target == 0)
            {
                return ans.push_back(ds);
            }
            return;
        }

        // pickup the element
        if (arr[index] <= target)
        {
            ds.push_back(arr[index]);
            findCombination(index, target - arr[index], arr, ans, ds);
            ds.pop_back();
        }
        // dont pick up the element
        findCombination(index + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, target, candidates, ans, ds);

        return ans;
    }
};