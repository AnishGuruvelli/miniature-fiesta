class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int s = *min_element(nums.begin(), nums.end());
        int g = *max_element(nums.begin(), nums.end());

        // Approach 1: checking every number

        // for (int i = s; i >= 1; i--)
        //     if (s % i == 0 && g % i == 0)
        //         return i;

        // return 1;


        // Approach 2: using '-' operator

        while (s != g)
        {
            if (g > s)
                g = g - s;
            else
                s = s - g;
        }
        return s;
        // do dry run with 9 and 6


        // Approach 3: using stl

        // return gcd(
        //     *max_element(nums.begin(), nums.end()),
        //     *min_element(nums.begin(), nums.end()));
    }
};