// mad question IT IS: FREQUENCY MEANING EVERYTIME U USE PRIORITY QUEUE, ITS A MUST, PLUS TRY TO DO IT ON OWN FIRST, MADD

class Solution
{
public:
    string frequencySort(string s)
    {

        // Count the frequency
        unordered_map<char, int> mp;
        for (auto i : s)
        {
            mp[i]++;
        }

        // priority queue will maintain the decreasing order
        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        // Generate the required answer
        string ans = "";
        while (!pq.empty())
        {

            pair<int, char> p = pq.top();
            pq.pop();

            while (p.first--)
            {
                ans += p.second;
            }
        }
        return ans;
    }
};