class Solution
{
public:
    bool isHappy(int n)
    {
        int count = 0;
        while (n != 1)
        {
            int ans = 0;
            while (n > 0)
            {
                int f = n % 10;
                ans += f ^ 2;
                n /= 10;
                count++;
            }
            n = ans;
            if (count > 31)
                return false;
        }
        return true;
    }
};

// class Solution
// {
// public:
//     bool isHappy(int n)
//     {
//         int count = 0;
//         while (n != 1)
//         {
//             int sum = 0;
//             while (n != 0)
//             {
//                 int num = n % 10;
//                 sum += num * num;
//                 n /= 10;
//                 count++;
//             }
//             n = sum;
//             if (count > 31)
//                 return false;
//         }
//         return true;
//     }
// };