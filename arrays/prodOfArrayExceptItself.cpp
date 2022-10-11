class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 1);
        int post = 1, pre = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] = pre;
            pre = pre * nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            result[i] = result[i] * post;
            post = post * nums[i];
        }
        return result;
    }
};

/*
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prod = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prod = prod * nums[i];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(prod / nums[i]);
        }
        return ans;
    }
};
*/