class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<int> s1, s2;

        for (auto i : S)
        {
            if (i == '#' && !s1.empty())
                s1.pop();
            else if (i != '#')
                s1.push(i);
        }

        for (auto i : T)
        {
            if (i == '#' && !s2.empty())
                s2.pop();
            else if (i != '#')
                s2.push(i);
        }

        // string str1, str2;
        // while (!s1.empty())
        // {
        //     str1.push_back(s1.top());
        //     s1.pop();
        // }
        // while (!s2.empty())
        // {
        //     str2.push_back(s2.top());
        //     s2.pop();
        // }
        // return str1 == str2;

        return s1 == s2;
    }
};