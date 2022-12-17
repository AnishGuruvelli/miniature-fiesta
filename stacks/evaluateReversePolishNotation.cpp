class Solution
{
    long resolvedAns(long a, long b, char op)
    {
        if (op == '+')
            return a + b;
        else if (op == '-')
            return a - b;
        else if (op == '*')
            return (long)a * b;
        else
            return a / b;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            // it is an operator
            if (tokens[i].size() == 1 && tokens[i][0] < 48)
            {
                long integer2 = s.top();
                s.pop();
                long integer1 = s.top();
                s.pop();
                string func = tokens[i];
                long answer = resolvedAns(integer1, integer2, func[0]);
                s.push(answer);
            }

            // it is a number
            else
                s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};