class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;

        int res = 0, check = 0;

        for (auto x : s)
            mp[x]++;

        for (auto x : mp)
        {
            if (x.second % 2 != 0)
            {
                check = 1;
                res += x.second - 1;
            }
            else
                res += x.second;
        }

        if (check)
            return res + 1;

        return res;
    }
};

// class Solution
// {
// public:
//     int longestPalindrome(string s)
//     {
//         unordered_map<char, int> map;

//         for (int i = 0; i < s.length(); i++)
//             map[s[i]]++;

//         int cnt = 0;

//         for (auto i : map)
//             if (i.second % 2 != 0)
//                 cnt++;

//         if (cnt > 1)
//             return s.length() - cnt + 1;

//         return s.length();
//     }
// };