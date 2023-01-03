// Time Complexity : O(n)
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        // Initialize rightSum to store the sum of all the numbers strictly to the index's right
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        
        // Initialize leftSum to store the sum of all the numbers strictly to the index's left
        int leftSum = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            rightSum -= nums[i];

            if (leftSum == rightSum)
                return i;

            leftSum += nums[i];
        }
        
        return -1;
    }
};


// wasnt working for some reason

// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         int sum1=0, sum2=0, index=0;
//         vector<int> ans;
//         for(auto i:nums){
//             sum1+=i;
//             ans.push_back(sum1);
//         }
//         reverse(nums.begin(), nums.end());
//         for(auto i:nums){
//             sum2+=i;
//             for(int j=0;j<ans.size()-1;j++){
//                 if(sum2 == ans[j]){
//                     index = j;
//                 }
//             }
//         }
//         return index;
//     }
// };

// // 1 8 11 17 22 28
// // 6 11 17 20 27 28 => 28 27 20 17 11 6

// // 2 3 2
// // -1 0 2

// // 1 3 6
// // 3 5 6