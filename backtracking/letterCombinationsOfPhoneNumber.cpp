// class Solution
// {
// public:
//     void solve(string digits, vector<string> &ans, int index, string &output, string phone[])
//     {
//         if (index >= digits.size())
//         {
//             ans.push_back(output);
//             return;
//         }
//         int number = digits[index] - '0';
//         string value = phone[number];
//         for (int i = 0; i < value.size(); i++)
//         {
//             output.push_back(value[i]);
//             solve(digits, ans, index + 1, output, phone);
//             output.pop_back();
//         }
//     }

//     vector<string> letterCombinations(string digits)
//     {
//         vector<string> ans;
//         if (digits.size() == 0)
//         {
//             return ans;
//         }
//         string phone[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         string output;

//         solve(digits, ans, 0, output, phone);
//         return ans;
//     }
// };

/// OR THIS SOLUTION BELOW

class Solution
{
public:
    unordered_map<int, vector<char>> phone;
    vector<string> ans;
    void init()
    {
        phone[2] = {'a', 'b', 'c'};
        phone[3] = {'d', 'e', 'f'};
        phone[4] = {'g', 'h', 'i'};
        phone[5] = {'j', 'k', 'l'};
        phone[6] = {'m', 'n', 'o'};
        phone[7] = {'p', 'q', 'r', 's'};
        phone[8] = {'t', 'u', 'v'};
        phone[9] = {'w', 'x', 'y', 'z'};
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return vector<string>();
        init();
        string output;
        backtrack(digits, 0, output);
        return ans;
    }
    void backtrack(string &digits, int index, string &output)
    {
        if (index == digits.size())
        {
            ans.push_back(output);
        }
        else
        {
            int digit = digits[index] - '0';
            for (int i = 0; i < phone[digit].size(); i++)
            {
                output.push_back(phone[digit][i]);
                backtrack(digits, index + 1, output);
                output.pop_back();
            }
        }
    }
};
