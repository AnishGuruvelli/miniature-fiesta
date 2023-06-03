class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int c)
    {
        int n = flowerbed.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (flowerbed[i] == 0)
            {
                if ((i == 0 || flowerbed[i - 1] == 0) &&
                    (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
                {
                    flowerbed[i] = 1;
                    count++;
                    if (count >= c)
                        return true;
                }
            }
            cout << count << endl;
        }
        return count >= c;
    }
};