class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto i : nums)
            mp[i]++;

        // unordered_map<int, int>::iterator it = mp.begin();
        // while(it!=mp.end()){
        for (auto it : mp)
            if ((it.second) == 1)
                return it.first;

        return -1;
    }
};

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         unordered_map<int, int> a;
//         for (auto x : nums)
//             a[x]++;
//         for (auto z : a)
//             if (z.second == 1)
//                 return z.first;
//         return -1;
//     }
// };

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         for (int i = 1; i < nums.size(); i += 2)
//         {
//             if (nums[i] != nums[i - 1])
//                 return nums[i - 1];
//         }
//         return nums[nums.size() - 1];
//     }
// };