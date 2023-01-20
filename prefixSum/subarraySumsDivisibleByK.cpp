/// CRAZY HARD +++ DAMN HARD +++ EXPLANATION
/// https://www.youtube.com/watch?v=6nD404xYEMw


// using vectors

// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         vector<int> output(k, 0);
//         // prefixModSum is used to store sum of all prefix mods
//         int prefixModSum = 0;
//         int res = 0;
//         output[0] = 1;
//         for(int i = 0; i < nums.size(); i++){
//             // (nums[i] % k + k) is used to avoid nagative remsinder
//             prefixModSum = (prefixModSum + nums[i] % k + k) % k;
//             //If in test case, only positive number given like [5,0,5,3] then
//             //prefixModSum = prefixModSum + nums[i] % k;
//             // Add the count of subarrays that have the same remainder
//             res = res + output[prefixModSum];
//             output[prefixModSum]++;
//         }
//         return res;
//     }
// };

// using maps

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        int currentSum = 0;
        int ans = 0;
        mp[0]++;

        for (auto x : nums)
        {
            currentSum += x;
            int mod = (currentSum % k + k) % k;
            // https://leetcode.com/problems/subarray-sums-divisible-by-k/solutions/3070599/day-19-explanation-with-diagram-prefix-sum-and-hashmap-o-n-time-and-o-n-space/
            // abt why u have to do mod twice

            // check if mod already present
            if (mp.find(mod) != mp.end())
                ans += mp[mod];

            mp[mod]++;
        }
        return ans;
    }
};