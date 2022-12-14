class Solution
{
public:
    bool isEqual(string s1, string s2)
    {
        if (s1.size() < s2.size()) // is less than : take note of this
            return false;
        for (int i = 0; i < s2.size(); i++)
            if (s1[i] != s2[i])
                return false;
        return true;
    }
    int strStr(string haystack, string needle)
    {
        // return haystack.find(needle);

        if (needle.size() == 0)
            return 0;
        for (int i = 0; i < haystack.size(); i++)
            if (haystack[i] == needle[0] && isEqual(haystack.substr(i), needle))
                return i;

        return -1;
    }
};

// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         return haystack.find(needle);
//     }
// };