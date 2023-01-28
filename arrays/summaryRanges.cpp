// 2pointer approach

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        int len = nums.size(), i = 0, j;
        string temp;

        while (i < len)
        {
            j = i + 1;
            while (j < len && nums[j - 1] + 1 == nums[j])
                j++;

            temp = to_string(nums[i]) + (j - i > 1 ? "->" + to_string(nums[j - 1]) : "");
            res.push_back(temp);
            i = j;
        }
        return res;
    }
};