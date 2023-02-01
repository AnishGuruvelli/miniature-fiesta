class Solution
{
public:
    int arrangeCoins(int sum)
    {
        int count = 0;
        int i = 1;
        while (sum > 0)
        {
            sum -= i;
            i++;
            count++;
        }
        return sum == 0 ? count : count - 1;
    }
};