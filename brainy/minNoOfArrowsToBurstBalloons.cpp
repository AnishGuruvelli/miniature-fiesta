class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;

        sort(points.begin(), points.end(), comp);

        int arrows = 1;
        int last = points[0][1];

        // [[-2147483648,2147483647]] : cuz of such testcases, where ans should be one,
        // in the second soln, below this one, ans will come as 0, so instead we make the
        // loop from i = 1 and then initialize the arrows as 1
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > last)
            {
                arrows++;
                last = points[i][1];
            }
        }
        return arrows;
    }
};

// class Solution
// {
// public:
//     int findMinArrowShots(vector<vector<int>> &points)
//     {
//         if (points.size() == 0)
//             return 0;

//         sort(points.begin(), points.end());

//         // for(int i=0;i<points.size();i++){
//         //     for(int j=0;j<points[0].size();j++){
//         //         cout<<points[i][j]<<" ";
//         //     }
//         // }

//         int arrows = 0;
//         int lastpoint = INT_MIN;

//         for (int i = 0; i < points.size(); i++)
//         {
//             if (points[i][0] > lastpoint)
//             {
//                 lastpoint = points[i][1];
//                 arrows++;
//             }
//             lastpoint = min(lastpoint, points[i][1]);
//         }
//         return arrows;
//     }
// };

// Ex: [[10,16],[2,8],[1,6],[7,12]]
// 1 6 2 8 7 12 10 16