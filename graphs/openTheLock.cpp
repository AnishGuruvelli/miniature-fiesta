class Solution
{
public:
    vector<string> helper(string key)
    {
        vector<string> res;
        for (int i = 0; i < 4; i++)
        {
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
        }
        return res;
    }
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        unordered_map<string, bool> visited;

        if (deadendsSet.find("0000") != deadendsSet.end())
            return -1;

        // if (binary_search(deadends.begin(), deadends.end(), "0000"))
        // return -1;

        queue<string> q;
        q.push("0000");

        int count = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                string t = q.front();
                q.pop();
                if (t == target)
                    return count;

                vector<string> v = helper(t);
                for (auto vv : v)
                {
                    // works with or without the above statement
                    if (vv == target)
                        return count + 1;
                        
                    if (deadendsSet.find(vv) == deadendsSet.end() && visited[vv] == false)
                    {
                        q.push(vv);
                        visited[vv] = true;
                    }
                }
            }
            count++;
        }

        return -1;
    }
};