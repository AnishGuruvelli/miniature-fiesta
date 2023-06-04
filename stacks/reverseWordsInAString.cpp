// this wont work for the last word // brilliant question

// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         stack<string> st;

//         for (int i = 0; i < n; i++)
//             for (int j = i + 1; j < n; j++)
//                 if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
//                     if (s[j] == ' ')
//                     {
//                         st.push(s.substr(i, j - i));
//                         i = j + 1;
//                     }

//         string ans = "";
//         while (!st.empty())
//         {
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        string word = "";
        for (char c : s)
        {
            if (c != ' ')
                word.push_back(c);
            else
            {
                if (!word.empty())
                {
                    st.push(word);
                    word = "";
                }
            }
        }
        if (!word.empty())
            st.push(word);

        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
            if (!st.empty())
                ans += " ";
        }
        return ans;
    }
};
