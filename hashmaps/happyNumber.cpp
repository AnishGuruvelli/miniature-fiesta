// array approach

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

// hashtable approach

class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
            return true;

        unordered_map<int, int> map;
        while (n > 0)
        {
            int sum = 0;
            while (n > 0)
            {
                int x = n % 10;
                sum += x * x;
                n = n / 10;
            }
            n = sum;
            map[n]++;
            if (map[n] > 1)
                return false;
            if (n == 1)
                return true;
        }
        return false;
    }
    // 18 = 65 = 61 = 37 = 58 = 89 = 145 = 42 = 20 = 4 = 16 = 37
    // (there's always a repitition)
};