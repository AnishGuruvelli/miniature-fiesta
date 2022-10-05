// brute force

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;

        for (int i = 0; i <= nums.size() - k; i++)
        {
            int max = nums[i];
            for (int j = i + 1; j < i + k; j++)
            {
                if (max < nums[j])
                    max = nums[j];
            }
            ans.push_back(max);
        }
        return ans;
    }
};

// deque method

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size() - k; i++)
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