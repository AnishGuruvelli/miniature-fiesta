// do this before find missing positive
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
// 448. Find All Numbers Disappeared in an Array


// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for(auto i: nums)
//             mp[i]++;

//         int maxi = *max_element(nums.begin(), nums.end());
//         vector<int> v;

//         for(int i=1;i<nums.size();i++)
//             if(mp[i] == 0) v.push_back(i);

//         if(v.size() == 0) v.push_back(maxi+1);

//         // fails at this case [1,2], ans is suppose to be [], but ans i get is [3]

//         return v;
//     }
// };

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++)

            freq[nums[i]]++;

        for (int i = 1; i <= n; i++)
            if (freq[i] == 0)
                ans.push_back(i);

        return ans;
    }
};