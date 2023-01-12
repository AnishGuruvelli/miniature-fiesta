// we can solve it in n-time using linear search
// but we can take advantage of sorted array and we will use
// binary search to solve this problem

// class Solution
// {
// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         vector<int> v;

//         for (int i = 0; i < nums.size(); i++)
//             if (nums[i] == target)
//                 v.push_back(i);

//         int n = v.size();

//         if (v.empty())
//         {
//             v.push_back(-1);
//             v.push_back(-1);
//         }

//         if (v.size() == 1)
//             v.push_back(v.front());

//         if (v.size() > 2)
//             v.erase(v.begin() + 1, v.end() - 1);

//         return v;
//     }
// };

class Solution
{
public:
    int solve(vector<int> &nums, int l, int r, int target)
    {
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int index = solve(nums, 0, n - 1, target);
        int l = index, r = index;
        if (index == -1)
            return {-1, -1};

        // now solve separately
        while (1)
        {
            int left = solve(nums, 0, l - 1, target);
            int right = solve(nums, r + 1, n - 1, target);

            if (left == -1 && right == -1)
                break;

            if (left != -1)
                l = left;
            // updating the index that we get from the left side of the index .

            if (right != -1)
                r = right;
            // updating the index that we get from the right side of the index
        }
        return {l, r};
    }
};