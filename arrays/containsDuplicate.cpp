class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        return false;

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i+1; j < n; j++)
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


// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int> count;
//         for(auto i:nums)
//             if(++count[i]>1) return true;
//         return false;
//     }
// };