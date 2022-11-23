class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;

        if (n == 1)
            return 0;
        
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                ans = i;
        }
        
        return ans;
    }
};