// https://leetcode.com/problems/longest-subsequence-with-limited-sum/solutions/2948651/c-upper-bound-sorting-very-easy-to-understand/
// https://leetcode.com/problems/longest-subsequence-with-limited-sum/solutions/2499420/c-4-approaches-easy-to-advanced/?orderBy=most_votes&languageTags=cpp&topicTags=binary-search

// class Solution
// {
// public:
//     vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for (int i = 1; i < n; i++)
//             nums[i] = nums[i] + nums[i - 1];

//         int m = queries.size();
//         vector<int> ans(m);
//         for (int i = 0; i < m; i++)
//         {
//             int ind = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
//             ans[i] = ind;
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> answerQueries(vector<int> &v, vector<int> &q)
    {
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++)
            v[i] += v[i - 1];
        // 1 2 4 5 => 1 3 7 12

        vector<int> ans;
        for (int x : q)
        {
            int idx = upper_bound(v.begin(), v.end(), x) - v.begin();
            // https://www.geeksforgeeks.org/upper_bound-in-cpp/
            ans.push_back(idx);
        }
        return ans;
    }
};
