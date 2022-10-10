class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {

        unordered_map<int, int> mp;
        bool ans = false;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        unordered_map<int, int>::iterator it = mp.begin();

        while (it != mp.end())
        {
            if ((it->second) > 1)
            {
                ans = true;
                break;
            }
            it++;
        }
        return ans;

        //         int n = nums.size();
        //         sort(nums.begin(), nums.end());

        //         for (int i = 1; i < n; i++)
        //         {
        //             if (nums[i] == nums[i - 1])
        //             {
        //                 return true;
        //             }
        //         }
        //         return false;

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (nums[i] == nums[j])
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};