class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k--)
        {
            int c = pq.top();
            pq.pop();
            pq.push(sqrt(c));
        }
        long long ans = 0;
        while (!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            ans += x;
        }
        return ans;
    }
};