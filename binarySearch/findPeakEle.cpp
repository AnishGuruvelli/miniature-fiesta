// array method

// class Solution
// {
// public:
//     int findPeakElement(vector<int> &nums)
//     {
//         int n = nums.size();
//         int ans = 0;

//         if (n == 1)
//             return 0;

//         for (int i = 1; i < n; i++)
//             if (nums[i] > nums[i - 1])
//                 ans = i;

//         return ans;
//     }
// };

// binary search  method

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // support variables
        int l = 0, mid, r = nums.size() - 1;
        // edge cases:
        // mono-element input or first element as a peak
        if (!r || nums[0] > nums[1])
            return 0;
        // last element as a peak
        if (nums[r - 1] < nums[r])
            return r;
        // binary searching the input
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            else if (nums[mid] > nums[mid + 1])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};