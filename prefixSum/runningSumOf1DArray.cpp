class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int n = nums.size();

        // O(N^2) appraoch
        // int sum = 0;
        // vector<int> ans;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j <= i; j++)
        //     {
        //         sum += nums[j];
        //     }
        //     ans.push_back(sum);
        //     sum = 0;
        // }
        // return ans;


        // O(N) approach: traverse only once

        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        return nums;
    }
};