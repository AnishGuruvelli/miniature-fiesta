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
            // tokens[i].size() == 1 : this step is there to take in only operations,
            // as + - * / are also counted as 1 length, so if its -11, then size is
            // counted as 2, so it will go into else

            if (tokens[i].size() == 1 && tokens[i][0] < 48)
            // ascii values of signs and all :
            // https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
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