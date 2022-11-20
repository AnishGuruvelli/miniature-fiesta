class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int k = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k)
            {
                k++;
            }
        }
        return k;
    }
};
