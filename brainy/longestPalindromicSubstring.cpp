class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0, end = s.size() - 1;
        while (start < end)
            if (s[start++] != s[end--])
                return false;

        return true;
    }

    string longestPalindrome(string s)
    {
        string ans = "";
        int n = s.size();

        if (n == 0)
            return "";
        if (n == 1)
            return s;

        for (int i = 0; i < n; i++)
            for (int j = 1; j <= n - i; j++)
                if (isPalindrome(s.substr(i, j)))
                    // both i and j indexes are included
                    if (ans.size() < j)
                        ans = s.substr(i, j);

        return ans;
    }
};

// class Solution {
// public:
//     void helper(string &s, int start, int end, int n){

//         if(s[start] == s[end]){~
//             s.substr(start,end);
//             helper(s, start+1, end-1, n);
//         }
//         else{
//             helper(s, start+1, end, n);
//             // helper(s, start, end-1, n));
//         }
//     }

//     string longestPalindrome(string s) {
//         int n = s.size();
//         helper(s, 0, n-1, n);
//         return s;
//     }
// };