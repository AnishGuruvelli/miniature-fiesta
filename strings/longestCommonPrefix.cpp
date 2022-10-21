class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        string ans = "";

        for (int i = 0; i < strs[0].size(); i++)
        {
            char ch = strs[0][i];
            bool match = true;

            for (int j = 1; j < strs.size(); j++)
            {
                if (ch != strs[j][i])
                {
                    match = false;
                    break;
                }
            }
            if (match == false)
            {
                break;
            }
            else
            {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};

// @12:40 video link: https://www.youtube.com/watch?v=VTr3Nh7BadI: using tries