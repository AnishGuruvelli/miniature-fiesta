/*
The approach used is to first iterate through the given intervals, and keeping track of the index of the interval where the new interval should be inserted such that the intervals remain sorted. Then it will merge any overlapping intervals with the new interval and update its start and end times. Finally, it will insert the new interval into the correct position in the intervals and return the modified intervals.
The key idea behind this approach is to maintain the sorted order of the intervals, and to merge any overlapping intervals with the new interval.
By iterating through the intervals and keeping track of the index where the new interval should be inserted, we can ensure that the intervals remain sorted, and by merging any overlapping intervals with the new interval, we can ensure that the final output has no overlapping intervals.
*/

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0])
            res.push_back(intervals[i++]);
        
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval = {min(intervals[i][0], newInterval[0]),
                           max(intervals[i][1], newInterval[1])};
            i++;
        }
        res.push_back(newInterval);

        while (i < n)
            res.push_back(intervals[i++]);
        
        return res;
    }
};