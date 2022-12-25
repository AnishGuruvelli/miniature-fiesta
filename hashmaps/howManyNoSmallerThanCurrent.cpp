class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {

        // vector<int> ans = nums;
        // unordered_map<int, int> mp;
        // sort(ans.begin(), ans.end());
        // for (int i = 0; i < ans.size(); i++)
        //     if (mp.find(ans[i]) == mp.end())
        //         mp[ans[i]] = i;
        // for (int i = 0; i < ans.size(); i++)
        //     ans[i] = mp[nums[i]];
        // return ans;

        // fails at this case:
        // we cant traverse if the largest ele is at the end, then 0 will be printed either way.so j = i, is not valid, it should be from j = 0;

        vector<int> ans;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
                if (nums[i] > nums[j])
                    count++;

            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};