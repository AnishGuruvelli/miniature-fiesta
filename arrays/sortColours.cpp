// class Solution
// {
// public:
//     void sortColors(vector<int> &nums)
//     {
//         // sort(nums.begin(), nums.end());

//         // bubble sort
//         int i, j;
//         int n = nums.size();

//         // Last i elements are already in place

//         for (i = 0; i < n - 1; i++)
//             for (j = 0; j < n - i - 1; j++)
//                 if (nums[j] > nums[j + 1])
//                     swap(nums[j], nums[j + 1]);

//         return;
//     }
// };

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int temp = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j])
                {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
    }
};