class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0, j = s.length() - 1;

        while(i <= j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

// class Solution
// {
// public:
//     bool isPalindrome(int x)
//     {
//         // cant be used
//         // int y = reverse(x);
//         int number = x;
//         long long reverse = 0;

//         if (x < 0)
//             return false;

//         while (x != 0)
//         {
//             int temp = x % 10;
//             reverse = reverse * 10 + temp;
//             x = x / 10;
//         }

//         if (number == reverse)
//         {
//             return true;
//         }
//         return false;
//     }
// };

