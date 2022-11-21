class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        vector<int> ans;

        int n1 = nums1.size();
        int n2 = nums2.size();

        // we want nums1 to be bigger
        if (n1 < n2)
            swap(nums1, nums2);

        for (auto i : nums1)
            mp[i]++;

        for (auto i : nums2)
            if (mp.count(i) && --mp[i] >= 0)
                ans.push_back(i);

        return ans;
    }
};
