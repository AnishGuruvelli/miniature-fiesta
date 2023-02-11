class Solution
{
public:
    bool strongPasswordCheckerII(string p)
    {
        if (size(p) < 8)
            return false;

        bool low = false, upper = false, digit = false, special = false;

        for (auto c : p)
        {
            if (c >= 'a' and c <= 'z')
                low = true;
            else if (c >= 'A' and c <= 'Z')
                upper = true;
            else if (isdigit(c))
                digit = true;
            // if(i >= 33 or i <= 47) special++;
            else
                special = true;
        }

        // Check the 6th condition
        for (int i = 1; i < n; i++)
            if (password[i] == password[i - 1])
                return false;

        return (low and upper and digit and special)
    }
};
