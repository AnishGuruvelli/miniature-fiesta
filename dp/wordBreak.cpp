class Solution
{
public:
    int dp[301];
    int solve(string &s, int i, set<string> &mp)
    {
        if (i == s.size())
            return 1;
        if (dp[i] != -1)
            return dp[i];
            
        for (int j = i; j < s.size(); j++)
            if (mp.find(s.substr(i, j - i + 1)) != mp.end())
                if (solve(s, j + 1, mp))
                    return dp[i] = 1;

        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> mp;
        memset(dp, -1, sizeof(dp));
        for (auto word : wordDict)
            mp.insert(word);

        return solve(s, 0, mp);
    }
};

// class Solution
// {
// public:
//     int help(int i, string s, set<string> &wordDict)
//     {
//         if (i == s.size())
//             return 1;
//         string temp;
//         for (int j = i; j < s.size(); j++)
//         {
//             temp += s[j];
//             if (wordDict.find(temp) != wordDict.end())
//             {
//                 if (help(j + 1, s, wordDict))
//                     return 1;
//             }
//         }
//         return 0;
//     }
//     bool wordBreak(string s, vector<string> &wordDict)
//     {
//         set<string> st;
//         for (auto a : wordDict)
//             st.insert(a);
//         return help(0, s, st);
//     }
// };