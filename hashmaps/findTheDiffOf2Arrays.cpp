class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> a, b;
        
        for (int i : s1)
            if (s2.count(i) == 0)
                a.push_back(i);

        for (int i : s2)
            if (s1.count(i) == 0)
                b.push_back(i);

        return {a, b};
    }
};

/*
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp1;
        for (auto i : nums1)
            mp1[i]++;

        unordered_map<int, int> mp2;
        for (auto i : nums2)
            mp2[i]++;

        vector<vector<int>> ans;
        vector<int> a1, a2;

        for (auto i : nums1)
        {
            if (mp2[i] == 0)
                a1.push_back(i);
            mp2[i] = 1;
        }
        for (auto i : nums2)
        {
            if (mp1[i] == 0)
                a2.push_back(i);
            mp1[i] = 1;
        }
        return {a1, a2};
    }
};
*/