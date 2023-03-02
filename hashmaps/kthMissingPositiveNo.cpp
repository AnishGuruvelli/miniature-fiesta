// No of Missing Number till a particular index can be calculated as (Arr[index] - 1 - index )
// for eg :

//     [ 2 , 3 , 4 , 7 , 11 ]
//       0   1   2   3   4

//            *  Number of missing Number upto index 4 will be

//            *   Arr[4] - 1 - 4 => 11 - 1 - 4 => 6

// class Solution
// {
// public:
//     int findKthPositive(vector<int> &arr, int k)
//     {
//         int l = 0, r = arr.size() - 1;

//         while (l <= r)
//         {
//             int mid = l + (r - l) / 2;

//             if (arr[mid] - 1 - mid < k)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }

//         return l + k;
//     }
// };

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (int x : arr)
            mp[x]++;

        int num = 1;

        while (k > 0)
        {
            if (mp[num] == 0)
                k--;
            if (k == 0)
                return num;
            num++;
        }

        return -1;
    }
};
