// // Time Limit Exceeded
// Last Executed Input
// 67 / 107 testcases passed
// s1 =
// "trinitrophenylmethylnitramine"
// s2 =
// "dinitrophenylhydrazinetrinitrophenylmethylnitramine"
// this is O(n*m)
// class Solution
// {
// public:
//     unordered_set<string> ans;
//     void permutations(string s, int i, int n)
//     {
//         if (i == n)
//         {
//             ans.insert(s);
//             return;
//         }

//         for (int j = i; j < n; j++)
//         {
//             swap(s[i], s[j]);
//             permutations(s, i + 1, n);
//             swap(s[i], s[j]);
//         }
//         return;
//     }
//     bool check(vector<string> &res, string s, int index)
//     {
//         for (int i = 0; i < s.size(); i++)
//             for (int j = i; j < s.size(); j++)
//                 if (ans.find(s.substr(i, j - i + 1)) != ans.end())
//                     return true;
//         return false;
//     }
//     bool checkInclusion(string s1, string s2)
//     {
//         if (s1.size() > s2.size())
//             return false;
//         permutations(s1, 0, s1.size());
//         vector<string> res(ans.begin(), ans.end());
//         // for(auto i:res) cout<<i<<endl;
//         return check(res, s2, 0);
//     }
// };

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> cnt(26, 0);
        for (auto x : s1)
            cnt[x - 'a']++;

        int n1 = s1.size(), n2 = s2.size();

        for (int i = 0; i <= n2 - n1; i++)
        {
            vector<int> cnt2(26, 0);
            for (int j = i; j < i + n1; j++)
                cnt2[s2[j] - 'a']++;
            if (cnt == cnt2)
                return true;
        }
        return false;
    }
};

class Solution
{
public:
    bool isPermutation(string &s, string &t)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            m[t[i]]--;
        }

        for (auto &it : m)
            if (it.second != 0)
                return false;

        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        for (int i = 0; i <= n - m; i++)
        {
            string temp = s2.substr(i, m);
            if (isPermutation(s1, temp))
                return true;
        }
        return false;
    }
};

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> mp;
        for (auto i : s1)
            mp[i]++;

        int count = mp.size();
        int i = 0, j = 0;
        int k = s1.size();
        // Window Size

        while (j < s2.size())
        {
            if (mp.find(s2[j]) != mp.end())
            {
                mp[s2[j]]--;
                if (mp[s2[j]] == 0)
                    count--;
            }
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                if (count == 0) // Anagram found
                    return true;
                if (mp.find(s2[i]) != mp.end())
                {
                    mp[s2[i]]++;
                    if (mp[s2[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};
