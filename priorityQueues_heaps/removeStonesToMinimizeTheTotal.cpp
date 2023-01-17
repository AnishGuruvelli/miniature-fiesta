class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int, vector<int>> pq;

        for (auto i : piles)
            pq.push(i);

        while (k > 0)
        {
            int topEle = pq.top();
            // cout << topEle << endl;
            pq.pop();
            topEle -= floor(topEle / 2);
            // cout << topEle << endl;
            pq.push(topEle);
            k--;
        }

        int ans = 0;

        while (!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            ans += x;
        }
        
        return ans;
    }
};