class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> mp;
        int maxi = *max_element(nums.begin(), nums.end());

        for (auto x : nums)
            mp[x]++;
            
        if (maxi < 0)
            return 1;

        for (int i = 1; i < maxi; i++)
            if (mp[i] == 0)
                return i;

        return maxi + 1;
    }
};
