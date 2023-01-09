// time limit exceeded: so dp is the way to go to optimise the below solution

// class Solution
// {
// public:
//     bool isPalindrome(string s)
//     {
//         int start = 0, end = s.size() - 1;
//         while (start < end)
//             if (s[start++] != s[end--])
//                 return false;

//         return true;
//     }

//     string longestPalindrome(string s)
//     {
//         string ans = "";
//         int n = s.size();

//         if (n == 0)
//             return "";
//         if (n == 1)
//             return s;

//         for (int i = 0; i < n; i++)
//             for (int j = 1; j <= n - i; j++)
//                 if (isPalindrome(s.substr(i, j)))
//                     // both i and j indexes are included
//                     if (ans.size() < j)
//                         ans = s.substr(i, j);

//         return ans;
//     }
// };

class Solution
{
public:
    string palindromicSubstrings(string &s, int L, int R)
    {
        int n = s.size();
        while (L >= 0 && R < n) 
        // iterate until L and R cross the boundary
        {
            if (s[L] != s[R])
                break;
            L--;
            R++;
        }
        return s.substr(L + 1, R - 1 - L); 
        // return palindromic substring
    }

    void longestSubstring(string &new_s, string &res, int &lenMax)
    {
        if (new_s.size() > lenMax) // if
        {
            res = new_s;
            lenMax = new_s.size();
        }
    }

    string longestPalindrome(string s)
    {
        int lenMax = 0;
        string res;

        for (int i = 0; i < s.length(); i++)
        {
            string odd = palindromicSubstrings(s, i, i); 
            // start from same index for odd length palindrome: cuz there is only one middle ele
            longestSubstring(odd, res, lenMax);
            string even = palindromicSubstrings(s, i, i + 1); 
            // start from adjacent index for even length palindrome: middle ele is in between i & i+1
            longestSubstring(even, res, lenMax);
        }
        return res;
    }
};

// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.size();

//         // dp[i][j] will be false if substring s[i..j] is not palindrome, Else true
//         vector<vector<bool>> dp(n, vector<bool>(n, false));

//         // All substrings of length 1 are palindromes
//         for (int i = 0; i < n; i++)
//             dp[i][i] = true;

//         int start = 0, lenMax = 1;

//         // check for sub-string of length 2.
//         for (int i = 0; i < n - 1; i++)
//         {
//             if (s[i] == s[i + 1])
//             {
//                 dp[i][i + 1] = true;
//                 start = i;
//                 lenMax = 2;
//             }
//         }

//         // Check for sub-string of length greater than 2.
//         for (int k = 3; k <= n; k++) // k is length of substring
//         {
//             for (int i = 0; i < n - k + 1; i++) // Fix the starting index
//             {
//                 int j = i + k - 1; 
//                 // Get the ending index of substring from starting index i and length k

//                 // checking for sub-string from ith index to jth index if s[i+1] to s[j-1] is a palindrome
//                 if (dp[i + 1][j - 1] == true && s[i] == s[j])
//                 {
//                     dp[i][j] = true;

//                     if (k > lenMax)
//                     {
//                         lenMax = k;
//                         start = i;
//                     }
//                 }
//             }
//         }

//         return s.substr(start, lenMax); 
//         // print sub-string from start to lenMax
//     }
// };