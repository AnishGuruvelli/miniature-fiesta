// this will be wrong as it will search from beginning in each iteration,
// so even if it is not in order, it will still say true, so its not a subsequence

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int count = 0;
        for (int i = 0; i < t.size(); i++)
            for (int j = 0; j < s.size(); j++)
                if (t[i] == s[j])
                    count++;

        return count == s.size();
    }
};

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int j = 0;

        for (int i = 0; i < t.length() && j < s.length(); i++)
            if (t[i] == s[j])
                j++;

        return j == s.length();

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