// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {

        // O(N): TIME COMPLEXITY
        // int i = 0;
        // while (A[i] < A[i+1]) i++;
        // return i;

        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;

        while (low < high)
        {
            mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid + 1])
            {
                high = mid;
            }

            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};