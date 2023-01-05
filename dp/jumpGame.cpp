class Solution
{
public:
    bool helper(vector<int> &nums, int index, int n)
    {
        if (index == n - 1)
            return true;

        int reachable = index + nums[index];

        for (int i = index + 1; i <= reachable; i++)
            if (helper(nums, i, n))
                return true;

        return false;
    }
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        return helper(nums, 0, n);
    }
};

// bool canJump(vector<int> &nums)
// {
//     int distance = 0;
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         distance = max(distance, i + nums[i]);
//         if (distance == i)
//             return false;
//     }
//     return true;
// }