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
            int a = pq.top();
            // cout << a << endl;
            pq.pop();
            a -= floor(a / 2);
            // cout << a << endl;
            pq.push(a);
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