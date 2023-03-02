// class Solution
// {
// public:
//     int arrangeCoins(int sum)
//     {
//         int count = 0;
//         int i = 1;
//         while (sum > 0)
//         {
//             sum -= i;
//             i++;
//             count++;
//         }
//         return sum == 0 ? count : count - 1;
//     }
// };

class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long int low = 1;
        long long int high = n;
        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            long long int mid_filled = (mid * (mid + 1)) / 2;
            if (mid_filled == n)
                return mid;
            if (mid_filled > n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low - 1;
    }
};