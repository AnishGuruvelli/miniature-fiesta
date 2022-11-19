class Solution
{
public:
    bool isValid(string a)
    {
        stack<char> s;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '(' || a[i] == '{' || a[i] == '[')
            {
                s.push(a[i]);
            }
            else
            {
                if (s.empty())
                    return false;

                else if (a[i] == ')')
                {
                    if (s.top() == '(')
                        s.pop();
                    else
                        return false;
                }
                else if (a[i] == '}')
                {
                    if (s.top() == '{')
                        s.pop();
                    else
                        return false;
                }
                else if (a[i] == ']')
                {
                    if (s.top() == '[')
                        s.pop();
                    else
                        return false;
                }
            }
        }
        if (s.empty())
            return true;
        else
            return false;
    }
};

// stacks