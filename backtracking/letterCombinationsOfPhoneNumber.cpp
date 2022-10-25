class Solution
{
public:
    void solve(string digits, vector<string> ans, int index, string output, string phone[])
    {
        if (index >= digits.size())
        {
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = phone[number];
        for (int i = 0; i < value.size(); i++)
        {
            output.push_back(value[i]);
            solve(digits, ans, index + 1, output, phone);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.size() == 0)
        {
            return ans;
        }
        string phone[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output;

        solve(digits, ans, 0, output, phone);
        return ans;
    }
};