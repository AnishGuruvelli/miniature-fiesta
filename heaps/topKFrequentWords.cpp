class Solution
{
public:
    struct comparator
    {
        bool operator()(pair<int, string> &a, pair<int, string> &b)
        {
            if (a.first == b.first)
                // if frequency are equal put lexicographically greater element on top
                return a.second < b.second;
            else
                // if frequency are not equal put the elements on top which has less frequency
                return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        int n = words.size();
        unordered_map<string, int> mp;
        for (auto word : words)
            mp[word]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        for (auto x : mp)
        {
            if (pq.size() < k)
                pq.push({x.second, x.first});
            else
                if (pq.top().first < x.second || (pq.top().first == x.second && pq.top().second > x.first))
                {
                    pq.pop();
                    pq.push({x.second, x.first});
                }
        }
        // push all the elements from pq to res
        vector<string> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// But this solution fails, because of the defining of the min heap, something went wrong: which is why we dont generally use  greater<pair<int, stri; instead we make use of a seperate operator
// class Solution
// {
// public:
//     vector<string> topKFrequent(vector<string> &words, int k)
//     {
//         unordered_map<string, int> mp;
//         // min heap
//         priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
//         vector<string> ans;
//         for (auto i : words)
//             mp[i]++;

//         for (auto it : mp)
//         {
//             pq.push({it.second, it.first});
//             if (pq.size() > k)
//                 pq.pop();
//         }
//         while (!pq.empty())
//         {
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         sort(ans.begin(), ans.end());

//         return ans;
//     }
// };