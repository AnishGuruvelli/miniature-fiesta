class Solution
{
public:
    int search(vector<int> &a, int target)
    {
        int s = 0;
        int e = a.size() - 1;

        while (s <= e)
        {

            int mid = (s + e) / 2;
            if (target == a[mid])
            {
                return mid;
            }

            if (a[s] <= a[mid])
            {
                if (target >= a[s] && target <= a[mid])
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else
            {
                // start >= a[mid]
                if (target >= a[mid] && target <= a[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        return -1;
    }
};