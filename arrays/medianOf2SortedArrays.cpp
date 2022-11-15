// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// Brute Force:
               // 1.Merge Both Array
              // 2.Sort them
             // 3.Find Median
            // TIME COMPLEXITY: O(n)+O(nlogn)+O(n)
            // SPACE COMPLEXITY: O(1)
            
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;

        for (auto num : nums1)
        {
            ans.push_back(num);
        }
        for (auto num : nums2)
        {
            ans.push_back(num);
        }
        sort(ans.begin(), ans.end());

        int n = ans.size();
        int middle = n / 2;
        if (n % 2 == 0)
        {
            return (ans[middle - 1] + ans[middle]) / 2.0;
        }
        else
        {
            return ans[middle];
        }
    }
};