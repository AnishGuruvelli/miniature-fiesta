// https://www.geeksforgeeks.org/check-whether-the-given-string-is-palindrome-using-stack/
// using stacks

class Solution
{
public:
    bool isPalindrome(string str)
    {
        int l = 0, h = str.length() - 1;

        for (int i = 0; i <= h; i++)
            str[i] = tolower(str[i]);

        while (l <= h)
        {
            if (!(str[l] >= 'a' && str[l] <= 'z'))
                l++;

            else if (!(str[h] >= 'a' && str[h] <= 'z'))
                h--;

            else if (str[l] == str[h])
                l++, h--;

            else
                return false;
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