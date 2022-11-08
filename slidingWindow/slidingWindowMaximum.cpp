class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        } 
        return ans;
    }
};

// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         if (nums.empty())
//             return {};

//         int n = nums.size();
//         int leftMax[n], rightMax[n];

//         vector<int> result;

//         // Creates left maximum and right maximum arrays
//         for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
//         {
//             if (i % k == 0)
//                 leftMax[i] = nums[i];
//             else
//                 leftMax[i] = max(leftMax[i - 1], nums[i]);

//             if (j == n - 1 || (j + 1) % k == 0)
//                 rightMax[j] = nums[j];
//             else
//                 rightMax[j] = max(rightMax[j + 1], nums[j]);
//         }

//         // Pushes the maximum of each window in the result
//         for (int i = 0; i < n - k + 1; i++)
//             result.push_back(max(leftMax[i + k - 1], rightMax[i]));

//         return result;
//     }
// };

// BRUTE FORCE APPROACH

//     class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         vector<int> ans;
//         for (int i = 0; i <= n - k; i++)
//         {
//             int mx = INT_MIN;
//             for (int j = i; j < i + k; j++)
//             {
//                 mx = max(mx, nums[j]);
//             }
//             ans.push_back(mx);
//         }
//         return ans;
//     }
// };