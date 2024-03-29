// https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0rBT8io74a95xT-hDFZonNs&index=4
// intuition at 17mins

/// https://leetcode.com/problems/trapping-rain-water/
/// https://www.geeksforgeeks.org/trapping-rain-water/

class Solution
{
public:
    // int trap(vector<int> &height)
    // {
    //     if (height.empty())
    //         return 0;

    //     int ans = 0;

    //     for (int i = 0; i < height.size(); i++)
    //     {
    //         int left_max = 0;
    //         int right_max = 0;
    //         for (int j = i; j >= 0; j--)
    //             left_max = max(left_max, height[j]);
    //         for (int k = i; k <= height.size(); k++)
    //             right_max = max(right_max, height[k]);

    //         ans += min(left_max, right_max) - height[i];
    //     }
    //     return ans;
    // }

    // int trap(vector<int> &height)
    // {
    //     if (height.empty())
    //         return 0;

    //     int ans = 0;

    //     int size = height.size();

    //     vector<int> left_max(size), right_max(size);
    //     left_max[0] = height[0];
    //     for (int i = 1; i < size; i++)
    //     {
    //         left_max[i] = max(height[i], left_max[i - 1]);
    //     }
    //     right_max[size - 1] = height[size - 1];
    //     for (int i = size - 2; i >= 0; i--)
    //     {
    //         right_max[i] = max(height[i], right_max[i + 1]);
    //     }
    //     for (int i = 1; i < size - 1; i++)
    //     {
    //         ans += min(left_max[i], right_max[i]) - height[i];
    //     }
    //     return ans;
    // }

    // 2POINTER APPROACH: BEST ONE

    int trap(vector<int> &height)
    {
        int n = height.size();
        int ans = 0;
        int left_max = 0;
        int right_max = 0;
        int left = 0, right = n - 1;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                (height[left] >= left_max) ? (left_max = height[left]) : ans += (left_max - height[left]);
                left++;
            }
            else
            {
                (height[right] >= right_max) ? (right_max = height[right]) : ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};