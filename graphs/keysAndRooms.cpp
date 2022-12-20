// This is a straight fwd graph traversal problem and can be solved by BFS with a visited array. Idea is to go inside a room, mark it visited and go to all other rooms reachable from the keys present inside this current room. And so on till we have no more rooms are left to visit. Finally, check if we have visited all rooms. If so, return true.

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> visited(rooms.size(), false);
        
        queue<int> q;
        q.push(0); 
        // Start from room 0.
        
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int room = q.front();
                q.pop();
                visited[room] = true;
                for (int ele : rooms[room])
                    if (!visited[ele])
                        q.push(ele);
            }
        }
        return count(visited.begin(), visited.end(), true) == rooms.size();
    }
};
