class Solution
{
public:
    vector<string> ans;
    bool solve(string &s, unordered_set<string> &mp, int i, string res)
    {
        if (i == s.size())
            ans.push_back(res.substr(1));

        for (int j = i; j < s.size(); j++)
        {
            string temp = s.substr(i, j - i + 1);

            if (mp.find(temp) != mp.end())
                solve(s, mp, j + 1, res + " " + temp);
        }
        return false;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> mp;
        for (auto word : wordDict)
            mp.insert(word);

        solve(s, mp, 0, "");
        return ans;
    }
};
