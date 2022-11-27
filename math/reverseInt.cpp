class Solution
{
public:
    int reverse(int x)
    {
        long a, b, count = 0, ab = 0;
        // if (x < 0)
        // {
        //     count++;
        //     x = abs(x);
        // }

        while (x != 0)
        {
            a = x % 10;
            ab = ab * 10 + a;
            cout << ab << endl;
            x = x / 10;
            cout << x << endl;
        }

        // if (count > 0)
        // {
        //     ab *= -1;
        // }
        
        // long papa = -pow(2, 32);
        long papa = INT_MIN;
        // long baba = pow(2, 32) - 1;
        long baba = INT_MAX;
        
        if (ab < papa || ab > baba)
            return 0;

        return ab;
    }
};