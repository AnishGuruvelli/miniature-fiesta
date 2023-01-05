// class Solution
// {
// public:
//     bool uniqueOccurrences(vector<int> &arr)
//     {
//         unordered_map<int, int> m;
//         unordered_map<int, int> n;
        
//         for (auto it : arr)
//             m[it]++;

//         for (auto it : m){
//             n[it.second]++;
//             cout<<it.first<<" -> "<<it.second<<endl;
//             }

//         if (m.size() == n.size())
//             return true;
//         else
//             return false;
//     }
// };

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {

        int n = arr.size();

        // declare a map

        unordered_map<int, int> mp;

        // store the frequency of each element into map

        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        // declare a set

        unordered_set<int> s;

        // iterate over the map, and if we find any duplicate frequency then return false

        for (auto x : mp)
        {
            // if duplicate frequency found

            if (s.count(x.second))
                return false;

            // insert the frequency into set

            s.insert(x.second);
        }
        return true;
    }
};

// GREAT SOLUTION USING ARRAYS TOO: BRUTE FORCE

// class Solution
// {
// public:
//     bool uniqueOccurrences(vector<int> &arr)
//     {
//         vector<int> ans;
//         int size = arr.size();
//         int i = 0;
        
//         sort(arr.begin(), arr.end());

//         while (i < size)
//         {
//             int count = 1;
//             for (int j = i + 1; j < size; j++)
//             {
//                 if (arr[i] == arr[j])
//                     count++;
//                 else
//                     break;
//             }
//             ans.push_back(count);
//             i = i + count;
//         }
//         size = ans.size();
        
//         sort(ans.begin(), ans.end());
        
//         for (int i = 0; i < size - 1; i++)
//         {
//             if (ans[i] == ans[i + 1])
//                 return false;
//         }
//         return true;
//     }
// };