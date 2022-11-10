// https://www.geeksforgeeks.org/check-whether-the-given-string-is-palindrome-using-stack/
// using stacks

// https://leetcode.com/problems/valid-palindrome/description/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, h = s.length() - 1;

        for (int i = 0; i <= h; i++)
            s[i] = tolower(s[i]);

        while (l <= h)
        {
            if (!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9')))
            {
                l++;
            }
            else if (!((s[h] >= 'a' && s[h] <= 'z') || (s[h] >= '0' && s[h] <= '9')))
            {
                h--;
            }
            else if (s[l] == s[h])
            {
                l++;
                h--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

/*

bool isPalindrome(string s)
{
    int length = s.size();

    // Creating a Stack
    stack<char> st;

    // Finding the mid
    int i, mid = length / 2;

    for (i = 0; i < mid; i++)
    {
        st.push(s[i]);
    }

    // Checking if the length of the string
    // is odd, if odd then neglect the
    // middle character
    if (length % 2 != 0)
    {
        i++;
    }

    char ele;
    // While not the end of the string
    while (s[i] != '\0')
    {
        ele = st.top();
        st.pop();

        // If the characters differ then the
        // given string is not a palindrome
        if (ele != s[i])
            return false;
        i++;
    }

    return true;
}

*/