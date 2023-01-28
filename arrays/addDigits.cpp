// class Solution
// {
// public:
//     int addDigits(int num)
//     {
//         while ((to_string(num).size()) != 1)
//         {
//             int sum = 0;
//             while (num != 0)
//             {
//                 int x = num % 10;
//                 sum += x;
//                 num = num / 10;
//             }
//             num = sum;
//         }
//         return num;
//     }
// };

class Solution
{
public:
    int addDigits(int num)
    {
        int sum = 0;
        while (num)
        {
            sum += (num % 10);
            num /= 10;
        }
        if (sum < 10)
            return sum;
        else
            return addDigits(sum);
    }
};