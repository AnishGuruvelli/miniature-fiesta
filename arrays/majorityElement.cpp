class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        // OR SORTING
        // sort(nums.begin(), nums.end());
        // return nums[n/2];

        // HASHMAPs

        // unordered_map<int, int> m;

        // for (auto a : nums)
        // {
        //     m[a]++;
        //     if (m[a] > n / 2)
        //         return a;
        // }
        // return -1;

        // MOORE VOTING ALGORITHM

        int c = 0, v = 0; // c = candidate, and v = votes
        for (auto a : nums)
        {
            if (v == 0)
                c = a;
            if (c == a)
                v++;
            else
                v--;
        }
        return c;
    }
};

// BRUTE FORCE APPROACH

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int index = 1, maxCount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[i] == nums[j])
                    count++;
            }
            if (count > maxCount)
            {
                maxCount = count;
                index = i;
            }
        }
        if (maxCount > n / 2)
        {
            return nums[index];
        }
        else
            return -1;
    }
};

// BRUTE FORCE APPROACH

// int countEveryElements(vector<int> nums, int n)
// {
//     int count;
//     for (int i = 0; i < n; i++)
//     {

//         count = 0;
//         for (int j = 0; j < n; j++)
//             if (nums[j] == nums[i])
//                 count++;

//         if (count > n / 2)
//             return nums[i];
//     }

//     return -1;
// }
