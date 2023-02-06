// theres a way with bit manupulation too

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        // vector<int> nums2;
        // for (int i = n; i < n * 2; i++)
        // {
        //     cout << nums[i];
        //     nums2.push_back(nums[i]);
        // }
        // vector<int> ans;
        // for (int i = 0; i < n; i++)
        // {
        //     ans.push_back(nums[i]);
        //     ans.push_back(nums2[i]);
        // }
        // return ans;

        vector<int> res;

        int j = n;

        for (int i = 0; i < n; i++)
        {
            res.push_back(nums[i]);
            res.push_back(nums[j++]);
        }

        return res;
    }
};
