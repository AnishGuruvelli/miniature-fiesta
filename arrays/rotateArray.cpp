// // proud of myself, that i first thought about k = k - n; then  k = k & n

// class Solution
// {
// public:
//     void rotate(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         if (k > n)
//             k = k % n;
//         vector<int> ans;
//         for (int i = n - k; i < n; i++)
//             ans.push_back(nums[i]);
//         for (int i = 0; i < n - k; i++)
//             ans.push_back(nums[i]);
//         for (int i = 0; i < nums.size(); i++)
//             nums[i] = ans[i];
//         return;
//     }
// };

class Solution
{
public:
    void rotate(int nums[], int n, int k)
    {
        k = k % n;

        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        reverse(nums, nums + n - k);

        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums + n - k, nums + n);

        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums, nums + n);
    }
};