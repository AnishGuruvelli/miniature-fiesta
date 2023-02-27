// class Solution
// {
// public:
//     vector<int> divisibilityArray(string word, int m)
//     {
//         int n = word.size();
//         vector<int> ans(n, 0);
//         for (int i = 0; i < 1; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 string s = word.substr(i, j);
//                 int no = stoi(s);
//                 if (no % 3 == 0)
//                     ans[j] = 1;
//             }
//         }
//     }
// };

class Solution
{
public:
    vector<int> divisibilityArray(string word, int m)
    {
        int n = word.size();
        vector<int> ans(n, 0);
        long num = 0;
        for (int i = 0; i < n; i++)
        {
            int digit = word[i] - '0';
            num = (num * 10 + digit) % m;
            if (num == 0)
                ans[i] = 1;
        }
        return ans;
    }
};