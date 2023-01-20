class Solution
{
public:
    void helper(vector<vector<int>> &ans, vector<int> &res, vector<int> &nums, int index, int n)
    {
        if (index == n)
        {
            if (res.size() > 1)
                ans.push_back(res);
            return;
        }

        // pickup the element
        if (res.size() == 0 || nums[index] >= res.back())
        {
            res.push_back(nums[index]);
            helper(ans, res, nums, index + 1, n);
            res.pop_back();
        }
        // dont pick up the element
        helper(ans, res, nums, index + 1, n);
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> res;
        int n = nums.size();
        helper(ans, res, nums, 0, n);

        // return ans;
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

// class Solution
// {
// public:
//     // Recursive function to find all increasing subsequences
//     void solve(vector<int> nums, int index, vector<int> output, set<vector<int>> &ans)
//     {
//         // Base case: if we have reached the end of the input array
//         if (index >= nums.size())
//         {
//             // Only insert into ans if output has more than one element
//             if (output.size() > 1)
//                 ans.insert(output);
//             return;
//         }
//         // If output is empty or current element is greater than or equal to the last element in output
//         if (output.size() == 0 || nums[index] >= output.back())
//         {
//             output.push_back(nums[index]);
//             solve(nums, index + 1, output, ans);
//             output.pop_back();
//         }
//         solve(nums, index + 1, output, ans);
//     }

//     vector<vector<int>> findSubsequences(vector<int> &nums)
//     {
//         // Initialize output and set to store all increasing subsequences
//         vector<int> output;
//         set<vector<int>> ans;
//         // Call recursive function to find all increasing subsequences
//         solve(nums, 0, output, ans);
//         // Return ans as a vector
//         return vector(ans.begin(), ans.end());
//     }
// };