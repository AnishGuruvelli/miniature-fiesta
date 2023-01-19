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
            mp1[s[i]] = i + 1;
            mp2[t[i]] = i + 1;
        }
        return true;
    }
};

// class Solution
// {
// public:
//     bool isIsomorphic(string s, string t)
//     {
//         // Two maps for s,t strings
//         unordered_map<char, int> map1;
//         unordered_map<char, int> map2;

//         for (int i = 0; i < s.length(); i++)
//         {
//             // insert each character if string s and t into seperate map
//             map1[s[i]] = i + 1;
//             map2[t[i]] = i + 1;
//         }

//         for (int i = 0; i < s.length(); i++)
//         {
//             // compare the maps if not equal return false;
//             if (map1[s[i]] != map2[t[i]])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// class Solution
// {
// public:
//     bool isIsomorphic(string s, string t)
//     {
//         unordered_map<char, int> mp1, mp2;
//         // for(auto i: s)
//         //     mp1[i]++;
//         // for(auto i: t)
//         //     mp2[i]++;

//         for (int i = 0; i < s.size(); i++)
//         {
//             mp1[s[i]] = i;
//             mp2[t[i]] = i;
//         }

//         vector<int> v1, v2;
//         // this will take it in order only so no problem : even if its s=egg and t=dad,
//         // instead of add, even then it will return the correct output
//         for (auto it1 : mp1)
//             v1.push_back(it1.second);
//         for (auto it2 : mp2)
//             v2.push_back(it2.second);

//         return v1 == v2;
//     }
// };