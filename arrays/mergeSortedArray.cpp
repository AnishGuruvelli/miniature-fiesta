class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> v;
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {

            if (nums1[i] > nums2[j])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else
            {

                v.push_back(nums1[i]);
                i++;
            }
        }

        while (i < m)
        {
            v.push_back(nums1[i]);
            i++;
        }

        while (j < n)
        {
            v.push_back(nums2[j]);
            j++;
        }
        nums1 = v;
    }
};

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};