// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         sort(nums.begin(), nums.end(), greater<int>());

//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (i == k)
//             {
//                 return nums[k - 1];
//             }
//         }
//         return 0;
//     }
// };

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // for maxHeap this is the format: for smallest element:
        // arranges in descending order
        // priority_queue<int> pq;

        // for minHeap below is the format: for largest element:
        // arranges in ascending order
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);

            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
