class Solution
{
public:
    unordered_map<char, int> mp;
    bool isValid(string &str1, string &str2)
    {
        int n1 = str1.size(), n2 = str2.size();
        int maxsize = max(n1, n2);
        for (int i = 0; i < maxsize; i++)
        {
            int c1 = i < n1 ? mp[str1[i]] : -1;
            int c2 = i < n2 ? mp[str2[i]] : -1;
            if (c1 == c2)
                continue;
            else if (c1 < c2)
                return true;
            else
                return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string> &words, string order)
    {
        for (int i = 0; i < order.size(); i++)
            mp[order[i]] = i;

        for (int word = 0; word < words.size() - 1; word++)
            if (!isValid(words[word], words[word + 1]))
                return false;

        return true;
    }
};
