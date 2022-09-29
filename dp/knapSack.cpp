class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        if (W == 0 || N == 0)
        {
            return 0;
        }
        if (wt[N - 1] > W)
        {
            return knapSack(N - 1, W, val, wt);
        }
        else
        {
            int include = val[N - 1] + knapSack(N - 1, W - wt[N - 1], val, wt);
            int exclude = 0 + knapSack(N - 1, W, val, wt);
            return max(include, exclude);
        }
    }
};