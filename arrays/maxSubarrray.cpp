// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
//  KADANE'S ALGORITHM

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int n = nums.size();
        int maxSoFar = INT_MIN;
        int maxUntilHere = 0;

        for (int i = 0; i < n; i++)
        {

            maxUntilHere += nums[i];
            if (maxUntilHere > maxSoFar)
            {
                maxSoFar = maxUntilHere;
            }
            if (maxUntilHere < 0)
            {
                maxUntilHere = 0;
            }
        }
        return maxSoFar;
    }
};