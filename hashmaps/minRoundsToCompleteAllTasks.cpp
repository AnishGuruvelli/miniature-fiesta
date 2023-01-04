class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        for (auto i : tasks)
            mp[i]++;

        int count = 0;

        for (auto i : mp)
        {
            if (mp.second % 2 == 0)
            {
                count += mp.second / 2;
            }
            if (mp.second % 3 == 0)
            {
                count += mp.second / 3;
            }
            else
            {
                count += mp.second / 3;
            }
        }
        return count;
    }
};