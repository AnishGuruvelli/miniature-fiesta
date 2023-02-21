/// DAMN SMART ANSWER, COULDNT EVEN THINK OF THIS

// If the middle element is at an even index, then the single element must be on the right side of the array, since all the elements on the left side should come in pairs. Similarly, if the middle element is at an odd index, then the single element must be on the left side of the array.

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // unordered_map<int, int> mp;

        // for(auto i: nums)
        //     mp[i]++;

        // for(auto it: mp)
        //     if(it.second == 1) return it.first;

        // return -1;

        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = (left + right) / 2;

            if (mid % 2 == 1)
                mid--;

            if (nums[mid] != nums[mid + 1])
                right = mid;

            else
                left = mid + 2;
        }

        return nums[left];
    }
};
