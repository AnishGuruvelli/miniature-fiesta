class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp1[s[i]] != mp2[t[i]])
                return false;
            mp1[s[i]] = i;
            mp2[t[i]] = i;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char, int> mp1;
//         unordered_map<char, int> mp2;
//         // for(auto i: s)
//         //     mp1[i]++;
//         // for(auto i: t)
//         //     mp2[i]++;

//         for (int i = 0; i < s.size(); i++)
//         {
//             mp1[s[i]]=i;
//             mp2[t[i]]=i;
//         }

//         vector<int> v1;
//         vector<int> v2;
//         for(auto it1: mp1)
//             v1.push_back(it1.second);
//         for(auto it2: mp2)
//             v2.push_back(it2.second);

//         return v1==v2;
//     }
// };