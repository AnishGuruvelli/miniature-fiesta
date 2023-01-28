class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> mp1, mp2;
        for (auto i : s)
            mp1[i]++;

        char c;
        for (auto i : t)
        {
            mp2[i]++;
            if (mp2[i] > mp1[i])
            {
                c = i;
                break;
            }
        }
        return c;
    }
};