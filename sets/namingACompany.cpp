// https://leetcode.com/problems/naming-a-company/solutions/3162541/simple-diagram-example-for-intuition/

class Solution
{

#define ll long long

public:
    // long long distinctNames(vector<string> &ideas)
    // {
    //     unordered_set<string> map[26];
    //     for (string &name : ideas)
    //         map[name[0] - 'a'].insert(name.substr(1));

    //     long long res = 0;
    //     for (int i = 0; i < 25; i++)
    //     {
    //         for (int j = i + 1; j < 26; j++)
    //         {
    //             int total1 = 0, total2 = 0;
    //             for (auto &substring : map[i])
    //                 if (map[j].find(substring) == map[j].end())
    //                     total1++;

    //             for (auto &substring : map[j])
    //                 if (map[i].find(substring) == map[i].end())
    //                     total2++;

    //             res += total1 * total2;
    //         }
    //     }
    //     return res * 2;
    // }

    // Time Limit Exceeded
    // Last Executed Input
    // 73 / 89 testcases passed

    long long distinctNames(vector<string> &ideas)
    {
        map<string, int> mp;
        int c = 0, n = ideas.size();
        for (auto s : ideas)
            mp[s]++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string s1 = ideas[i], s2 = ideas[j];
                swap(s1[0], s2[0]);
                if (mp[s1] or mp[s2])
                    ;
                else
                    c++;
            }
        }
        return c;
    }
};
