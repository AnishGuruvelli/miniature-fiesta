class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (auto a : arr)
            mp[a]++;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &f : mp)
            pq.push(f.second);
        while (k > 0)
        {
            k -= pq.top();
            if (k >= 0)
                pq.pop();
        }
        return pq.size();
    }
};