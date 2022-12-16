class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // bool ans = false;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] == nums[j])
        //         {
        //             if (abs(i - j) <= k)
        //                 ans = true;
        //         }
        //     }
        // }
        // return ans;

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = mp.find(nums[i]);
            if (it != mp.end() && i - it->second <= k)
                return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};