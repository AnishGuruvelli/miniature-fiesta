// It initializes small to the first element of nums and mid to INT_MAX.
// The function iterates from the second element of nums onwards.
// If the current number is less than or equal to small, we update small to the current number.
// If the current number is greater than small but less than or equal to mid, we update mid to the current number.
// If the current number is greater than both small and mid, it means we have found an increasing triplet, so we return true.
// If we finish iterating through the entire vector without finding an increasing triplet, we return false.

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;

        int small = nums[0];
        int mid = INT_MAX;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= small)
                small = nums[i];
            else if (nums[i] <= mid)
                mid = nums[i];
            else
                return true;
        }

        return false;
    }
};

// for(int i=0;i<n-2;i++)
//     for(int j=i+1;j<n-1;j++)
//         for(int k=j+1;k<n;k++)
//             if (nums[i] < nums[j] && nums[j] < nums[k])
//                 return true;
// return false;