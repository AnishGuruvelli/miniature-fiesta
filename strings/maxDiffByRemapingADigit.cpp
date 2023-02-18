class Solution
{
public:
    int minMaxDifference(int no)
    {
        string str = to_string(no);
        int maxi = no, mini = no;

        for (char i = '0'; i <= '9'; i++)
        {
            for (char j = '0'; j <= '9'; j++)
            {
                if (i == j)
                    continue;

                replace(str.begin(), str.end(), i, j);
                int new_no = stoi(str);

                if (new_no > maxi)
                    maxi = new_no;
                if (new_no < mini)
                    mini = new_no;

                str = to_string(no);
            }
        }
        return maxi - mini;
    }
};