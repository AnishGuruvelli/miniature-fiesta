// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         unordered_map<int, int> mp;
//         vector<int> ans;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             int complement = target - nums[i];
//             if (mp.find(complement) != mp.end())
//             {
//                 ans.push_back(mp[complement]);
//                 ans.push_back(i);
//             }
//             mp[nums[i]] = i;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};