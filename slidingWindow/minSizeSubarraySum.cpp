/// DAMN HARDDDDD

// target =
// 11
// nums =
// [1,2,3,4,5]
// 9 / 20 testcases passed
// Output
// 0
// Expected
// 3

// which is why this doesnt work

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int res=INT_MAX;
//         int n= nums.size();
//         for(int i=1;i<n;i++)
//             nums[i] += nums[i-1];

//         // cout<<nums[n-1];

//         for(int i=0;i<n;i++){
//             for(int j=n-1;j>=0;j--){
//                 if(nums[j]-nums[i] == target)
//                     res = min(res, j-i);
//             }
//         }
//         return res<INT_MAX ? res : 0;
//     }
// };

// // 2 3 1 2 4 3
// // 2 5 6 8 12 15

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int ans = INT_MAX;
//         int n = nums.size();

//         for(int i = 1 ; i < n ; i++)
//             nums[i] = nums[i-1] + nums[i];

//         for(int i = 0 ; i < n ; i++){
//             if(nums[i]-target >= 0){
//                 int ind = upper_bound(nums.begin(), nums.end(), nums[i]-target) - nums.begin();
//                 ans = min(ans, i-ind+1);
//             }
//         }

//         return ans == INT_MAX ? 0 : ans;
//     }
// };

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int sum = 0;
        int minlength = INT_MAX;
        while (j < nums.size())
        {
            sum += nums[j]; // updating our sum everytime
            if (sum < target)
                j++;

            if (sum >= target)
            {
                while (sum >= target)
                {
                    minlength = min(minlength, j - i + 1);
                    // update out minlength whenever we hit the target
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
        }
        return (minlength == INT_MAX) ? 0 : minlength;
    }
};