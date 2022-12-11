class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        int maxi = INT_MIN;

        for (auto i : nums)
            mp[i]++;

        for (auto i : nums)
            if (mp.find(-i) != mp.end())
                maxi = max(maxi, i);

        if (maxi == INT_MIN)
            return -1;

        return maxi;
    }
};