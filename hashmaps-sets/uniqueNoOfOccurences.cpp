// SETS ARE USED FOR FREQUENCY ONLY, STROING AS THEY TAKE ONLY ONE INPUT: unordered_set<int> s; thats it just one int, and we can directly insert too which we cant do in hashmaps

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
        {
            mp[arr[i]]++;
        }

        // declare a set

        unordered_set<int> s;

        // iterate over the map, and if we find any duplicate frequency then return false

        for (auto x : mp)
        {
            // if duplicate frequency found

            if (s.count(x.second))
            {
                return false;
            }

            // insert the frequency into set

            s.insert(x.second);
        }

        return true;
    }
};

// HASHMAP WAY OF DOING IT

// class Solution
// {
// public:
//     bool uniqueOccurrences(vector<int> &arr)
//     {
//         unordered_map<int, int> m;
//         unordered_map<int, int> n;
//         for (auto it : arr)
//         {
//             m[it]++;
//         }
//         for (auto it : m)
//         {
//             n[it.second]++;
//         }
//         if (m.size() == n.size())
//             return true;
//         else
//             return false;
//     }
// };

