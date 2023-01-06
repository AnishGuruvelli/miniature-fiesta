// class Solution
// {
// public:
//     string convertToTitle(int columnNumber)
//     {
//         string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//         int n = columnNumber;
//         string ans = "";
//         while (n > 0)
//         {
//             n = n - 1;
//             int k = n % 26;
//             ans.push_back(al[k]);
//             n = n / 26;
//         }

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// Decrement the columnNumber by 1 everytime just to make remainder work
// with the expression (columnNumber%26 + 'A').
// Match not 1 to 'A' but 0 to 'A', so that when I add the
// remainder to 'A' (which has the value range 0-25),
// it correctly matches the intended letter.

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res = "";
        while (columnNumber)
        {
            columnNumber--;
            res.push_back(columnNumber % 26 + 'A');
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};