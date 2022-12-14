class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it = m.begin(); it != m.end(); it++)
        {
            pq.push({it->second, it->first});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> result;

        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

// https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/

// https://github.com/neetcode-gh/leetcode/blob/main/cpp/neetcode_150/01_arrays_%26_hashing/top_k_frequent_elements.cpp