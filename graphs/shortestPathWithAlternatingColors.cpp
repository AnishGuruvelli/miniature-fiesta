// LEGIT GODLY QUESTION : VERY VERY CONCEPTUAL U DO THIS AND U R DONE WITH GRAPHS

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> adj(n); // neighbour color : line31

        for (auto &it : redEdges)
            adj[it[0]].push_back({it[1], 0});

        for (auto &it : blueEdges)
            adj[it[0]].push_back({it[1], 1});

        vector<int> ans(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        queue<vector<int>> q;

        q.push({0, 0, -1}); // node steps color
        visited[0][0] = true;
        visited[0][1] = true;
        ans[0] = 0;

        while (!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            int node = curr[0], steps = curr[1], prevColor = curr[2];

            for (auto &[neighbour, color] : adj[node])
                if (!visited[neighbour][color] && color != prevColor)
                {
                    visited[neighbour][color] = true;
                    q.push({neighbour, steps + 1, color});
                    if (ans[neighbour] == -1)
                        ans[neighbour] = steps + 1;
                }
        }
        return ans;
    }
};