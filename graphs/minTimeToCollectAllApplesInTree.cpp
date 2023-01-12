class Solution
{
public:
    int solve(vector<vector<int>> &adj, vector<bool> &apple, int start, int parent)
    {
        int time = 0;

        for (auto x : adj[start])
            if (x != parent)
                time = time + solve(adj, apple, x, start);

        if (start == 0)
            return time;

        if (time == 0 && apple[start] == false)
            return 0;

        return time + 2;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return solve(adj, hasApple, 0, -1);
    }
};