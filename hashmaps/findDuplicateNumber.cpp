class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // // brute force

        // int ans = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] == nums[j])
        //             ans = nums[i];
        //     }
        // }
        // return ans;

        // // sorting approach

        // sort(nums.begin(), nums.end());
        // int ans = 0;
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     if (nums[i - 1] == nums[i])
        //     {
        //         ans = nums[i];
        //     }
        // }
        // return ans;

        // unordered_map

            int ans = 0;
        unordered_map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }
        for (auto it : mp)
        {
            if (it.second > 1)
                ans = it.first;
        }
        return ans;
    }
};