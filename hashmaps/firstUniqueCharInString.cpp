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

        // 1st solution: 
        unordered_map<char, pair<int, int>> mp;
        int x = 0;
        for (auto i : s)
        // auto is being taken as char in this and not int, which is why its mp[i] inside
        {
            mp[i].first++;
            mp[i].second = x;
            x++;
        }

        for(auto it: s){
            if (mp[it].first == 1)
            {
                return mp[it].second;
            }
        }
        return -1;


        // 2nd solution:
        // unordered_map<char, int> m;


        // for (int i = 0; i < s.size(); i++)
        // // for (auto i: s)
        // {
        //     m[s[i]]++;
        //     // storing the number of times the character occured in the string
        // }
        // for (int i = 0; i < s.size(); i++)
        // {
        //     if (m[s[i]] == 1)
        //     {
        //         return i;
        //     }
        // }
        // return -1;
    }
};