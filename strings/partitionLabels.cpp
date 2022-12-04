// very imp question, we have to find out the last index of every char in a string 
// https://leetcode.com/problems/partition-labels/description/

// imp question
111
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> last(26, 0);

        // getting last index of every letter
        for (int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }

        vector<int> v;

        // 2 pointers both at the start only, and then l is for calculating the length between
        // the start and the last element of that letter.
        int start = 0, l = 0;

        for (int i = 0; i < s.size(); i++)
        {
            l = max(l, last[s[i] - 'a']);

            if (i == l)
            {
                v.push_back(i - start + 1);
                start = l + 1;
            }
        }
        return v;
    }
};