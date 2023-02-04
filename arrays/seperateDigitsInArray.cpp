class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        int no = 0;
        for (auto i : nums)
        {
            vector<int> res;
            while (i)
            {
                res.push_back(i % 10);
                i /= 10;
            }
            for (int k = res.size() - 1; k >= 0; k--)
                ans.push_back(res[k]);
        }
        return ans;
    }
};