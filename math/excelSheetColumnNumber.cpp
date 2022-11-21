class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        for (char ch : columnTitle)
        {
            int c = ch - 'A' + 1;
            result = 26 * result + c;
        }
        return result;
    }
};