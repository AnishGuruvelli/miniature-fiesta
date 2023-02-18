class Solution
{
public:
    int minimizeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // cout<<nums.back(); // 4
        int case1 = nums.back() - nums[2];
        // we are keeping first 3 as the same, as in we are changing first two to match the third
        int case2 = nums[nums.size() - 3] - nums[0];
        // we are keeping last 3 as the same, as in we are changing last two to match the third last
        int case3 = nums[nums.size() - 2] - nums[1];
        // we are changing first and last element to second and second last respectively
        return min({case1, case2, case3});
    }
};