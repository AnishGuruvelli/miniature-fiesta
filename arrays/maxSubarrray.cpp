// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

//  KADANE'S ALGORITHM : O(N)

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

// brute force approach: https://www.codingpanel.com/lesson/find-the-maximum-subarray-sum-in-on2-time-naive-method/: O(N^2)
    // import math
    // def maxSubArray(arr):
    // maximum = -math.inf
    // for i in range(0, len(arr)):
    //     sum=0
    //     for j in range(i, len(arr)):
    //     sum += arr[j]
    //     maximum = max(sum, maximum) #compare the resulting sum with the existing maximum value
    // return maximum    

// SECOND APPROACH: DIVIDE AND CONQUER  : O (NLOGN)
    // https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/
