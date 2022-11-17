class Solution
{
public:
    int firstUniqChar(string s)
    {

        if (!s.size())
            return -1;

        // none of this will work, cuz we have to store its index seperately for which we will need pair

        // unordered_map<char, int> mp;
        // int ans;
        // for (auto i : s)
        // {
        //     mp[i]++;
        // }

        // for (auto it : mp)
        // {
        //     if (it.second == 1)
        //     {
        //         ans = it.val;
        //         break;
        //     }
        // }
        // unordered_map<char, int>::iterator it = mp.begin();
        // while (it != mp.end())
        // {
        //     if (it->second == 1)
        //     {
        //         ans = it->first;
        //         break;
        //     }
        // }
        // return ans;

        unordered_map<char, pair<int, int>> mp;
        for (auto i : s)
        {
            mp[s[i]].first++;
            mp[s[i]].second = i;
        }
        for (auto it : mp)
        {
            if (it.second.first == 1)
            {
                return it.second.second;
            }
        }
        return -1;

        for (int i = 0; i <= s.size(); i++)
        {
            m[s[i]]++;
            // storing the number of times the character occured in the string
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};