class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int j = 0;

        for (int i = 0; i < t.length() && j < s.length(); i++)
            if (t[i] == s[j])
                j++;

        return (j == s.length());

        // int i = 0, j = 0;
        // while (i < s.size() && j < t.size())
        // {
        //     if (s[i] == t[j])
        //     {
        //         i++;
        //         j++;
        //     }
        //     j++;
        // }
        // return i == s.size();
    }
};
