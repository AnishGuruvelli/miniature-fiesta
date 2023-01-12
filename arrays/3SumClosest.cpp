// int threeSumClosest(vector<int> &a, int k)
// {
//     int n = a.size();
//     int ans = INT_MAX;

//     // sort for using two pointers
//     sort(a.begin(), a.end());

//     // fix 'x' in x+y+z=sum using a for loop
//     for (int i = 0; i < n - 2; i++)
//     {
//         // Use two sum for finding the y and z for k=(sum-x)

//         int sum = k - a[i];
//         int l = i + 1, h = n - 1;
//         int temp = 0;

//         while (l < h)
//         {

//             temp = a[l] + a[h];

//             if (temp == sum)
//             {

//                 // If we find triplet equal to sum then def it's the ans
//                 return a[l] + a[h] + a[i];
//                 l++, h--;
//             }

//             else if (temp < sum)
//                 l++;
//             else if (temp > sum)
//                 h--;
//         }

//         // else we look for value closest to k
//         // Note that we keep on getting closer to sum in each iteration
//         // i.e., in each iteration temp comes closer to k
//         // when we get out of the loop last temp was closest to k
//         //  so we update our ans if it is more closer to total sum
//         if (ans == INT_MAX || abs(sum - temp) < abs(k - ans))
//             ans = temp + a[i];
//     }

//     // return closest triplet sum
//     return ans;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end()); // I am going to use Two pointer for that i'm sorting it if you want to use some other approch feel free to do that;
        int n = nums.size();

        int sum = nums[0] + nums[1] + nums[2]; // Our Intial sum or assuption that intial three values are the closet sum
        for (int i = 0; i < n - 2; i++)
        { // n-2 Since we have taken n-1 in our point so no need to go beyond that
            // Implementing Two pointer technique
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int temp = nums[i] + nums[j] + nums[k]; // Temparory sum for comaprison
                if (abs(temp - target) < abs(sum - target))
                    sum = temp; // if we find batter or closer sum then we update the above sum value
                if (temp > target)
                {
                    k--; // if value is greater than target one just come one point right to left
                }
                else if (temp < target)
                {
                    j++; // if value is lower than target just come one point left to right
                }
                else
                    return target; // if value already found no need to go for other just return
            }
        }
        return sum;
    }
};