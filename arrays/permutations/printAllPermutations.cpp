class Solution
{
public:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    void nextPermutation(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

// class Solution
// {
// public:
//     void nextPermutation(vector<int> &nums)
//     {
//         int n = nums.size();

//         // direct stl method, not acceptable in interviews
//         // next_permutation(nums.begin(), nums.end());

//         int i, j;
//         for (i = n - 2; i >= 0; i--)
//             if (nums[i] < nums[i + 1])
//                 break;

//         if (i < 0)
//             reverse(nums.begin(), nums.end());

//         else
//         {
//             for (j = n - 1; j > i; j--)
//                 if (nums[j] > nums[i])
//                     break;

//             swap(nums[i], nums[j]);
//             reverse(nums.begin() + i + 1, nums.end());
//         }
//     }
// };

// 1 3 2
// 2 1 3

/*

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

For example, the next permutation of arr = [ 1, 2, 3 ] is[1, 3, 2].Similarly, the next permutation of arr = [ 2, 3, 1 ] is[3, 1, 2].While the next permutation of arr = [ 3, 2, 1 ] is[1, 2, 3] because[3, 2, 1] does not have a lexicographical larger rearrangement.

*/

