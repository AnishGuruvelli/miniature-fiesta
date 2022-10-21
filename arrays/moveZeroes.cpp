class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        while (j < n)
        {
            nums[j] = 0;
            j++;
        }
    }
};

// https://www.youtube.com/watch?v=mgzcjQ1x9Mw&list=PLKZaSt2df1gwgL9IH2rH9l9HcXbNx16hx&index=30
// https://leetcode.com/problems/move-zeroes/