// Four solutions possible;

//     Using prefix sum
//     Using mathematics
//     Using binary search
//     Using DP

// class Solution
// {
// public:
//     int pivotInteger(int n)
//     {
//         int totsum = 0;
//         // calculate total sum
//         for (int i = 1; i <= n; i++)
//             totsum += i;
//         // totalsum = 36 : for ex : 8

//         int presum = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             presum += i;                         // calculate prefix sum
//             if ((totsum - presum + i) == presum) // apply condition mentioned in the problem
//                 return i;
//         }
//         return -1;
//     }
// };

// class Solution
// {
// public:
//     int pivotIndex(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> pref(n);
//         vector<int> suffix(n);

//         int suma = 0;
//         for (int i = 0; i < n; i++)
//         {
//             pref[i] = suma;
//             suma = suma + nums[i];
//         }
//         int sumb = 0;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             suffix[i] = sumb;
//             sumb = sumb + nums[i];
//         }
//         int pos = -1;
//         for (int i = 0; i < n; i++)
//             if (pref[i] == suffix[i])
//             {
//                 pos = i;
//                 break;
//             }

//         return pos;
//     }
//     int pivotInteger(int n)
//     {
//         vector<int> ans(n + 1);

//         for (int i = 1; i <= n; i++)
//             ans[i] = i;

//         int res = pivotIndex(ans);
//         return res;
//     }
// };

// using mathematics

// class Solution
// {
// public:
//     bool checkperfectsquare(int n)
//     {
//         if (ceil((double)sqrt(n)) == floor((double)sqrt(n)))
//             return true;
//         return false;
//     }
//     int pivotInteger(int n)
//     {
//         int x = ((n) * (n + 1)) / 2;
//         if (checkperfectsquare(x))
//             return sqrt(x);

//         return -1;
//     }
// };

// binary search

class Solution
{
public:
    int pivotInteger(int n)
    {
        // support variables
        int sumRight, sumLeft, l = 1, r = n, m;
        // BS loop
        while (l <= r)
        {
            // updating loop variables
            m = (l + r) >> 1, sumLeft = (m * (m - 1)) >> 1, sumRight = ((n * (n + 1)) >> 1) - sumLeft - m;
            // match found
            if (sumLeft == sumRight)
                return m;
            // we went too high
            else if (sumLeft > sumRight)
                r = m - 1;
            // we went too low
            else
                l = m + 1;
        }
        return -1;
    }
};
