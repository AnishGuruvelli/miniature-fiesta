class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                ans.push_back(matrix[i][j]);
        }

        // // this is also one method with sorting
        // sort(ans.begin(),ans.end());
        // int p = k-1;
        // return ans[p];

        n = ans.size();

        priority_queue<int, vector<int>> pq;
        for (auto i : ans)
        {
            pq.push(i);

            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};