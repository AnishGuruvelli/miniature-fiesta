// https://leetcode.com/problems/majority-element/description/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        unordered_map<int, int> mp;
        int n = nums.size();

        for (auto i : nums)
        {
            mp[i]++;
        }

        for (auto it : mp)
        {
            if (it.second > n / 2)
            {
                return it.first;
            }
        }
        return -1;
    }
};

// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int start = 0;
//         int end = n - 1;
//         int mid = start + (end - start) / 2;

//         return nums[mid];
//     }
// };

// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {
//         int index = 1, maxCount = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//         {
//             int count = 0;
//             for (int j = i; j < n; j++)
//             {
//                 if (nums[i] == nums[j])
//                     count++;
//             }
//             if (count > maxCount)
//             {
//                 maxCount = count;
//                 index = i;
//             }
//         }
//         if (maxCount > n / 2)
//         {
//             return nums[index];
//         }
//         else
//             return -1;
//     }
// };
