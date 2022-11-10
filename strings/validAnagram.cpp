// https://leetcode.com/problems/valid-anagram/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            mp1[t[i]]++;
            mp2[s[i]]++;
        }

        if (mp1 == mp2)
            return true;
        else
            return false;

        //         int n1 = s.size();
        //         int n2 = t.size();

        //         if (n1 != n2)
        //         {
        //             return false;
        //         }
        //         sort(s.begin(), s.end());
        //         sort(t.begin(), t.end());
        //         if (s == t)
        //         {
        //             return true;
        //         }
        //         return false;
    }
};

