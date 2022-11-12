class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // reverse(s.begin(), s.end());

        int i = 0;
        int j = s.size() - 1;
        char temp;
        while (i < j)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }

    // stack<char> st;
    // for (auto i : s)
    // {
    //     st.push(s[i]);
    // }
    // s.clear();
    // for (int i = 0; i < s.size(); i++)
    // {
    //     char a = st.pop();
    //     s.push_back(a);
    // }
};