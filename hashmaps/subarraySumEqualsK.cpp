class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        // https://www.youtube.com/watch?v=HbbYPQc-Oo4
        // key is prefix sum, value is count of prefix sum
        
        int currSum = 0, ans = 0;
        mp[currSum] = 1;

        for (auto it : nums)
        {
            currSum += it;
            int find = currSum - k;
            if (mp.find(find) != mp.end())
                ans += mp[find];

            mp[currSum]++;
        }
        return ans;
    }
};