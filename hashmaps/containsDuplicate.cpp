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
    }
};