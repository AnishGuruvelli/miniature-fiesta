// class Solution
// {
// public:
//     double calcSlope(int x1, int y1, int x2, int y2)
//     {
//         return (double)(y2 - y1) / (double)(x2 - x1);
//     }

//     int maxPoints(vector<vector<int>> &points)
//     {
//         int ans = 1;
//         int n = points.size();

//         // slope of every point with selected point
//         for (int i = 0; i < n - 1; i++)
//         {
//             unordered_map<double, int> mp;
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (points[j][1] == points[i][1])
//                     mp[-90]++;
//                 // -90 is used to store the vertical line

//                 else
//                 {
//                     double x = calcSlope(points[i][0], points[i][1], points[j][0], points[j][1]);
//                     // storing the slope into map
//                     mp[x]++;
//                 }
//             }

//             // finding the max slope w.r.t.that selected point
//             int temp = 0;

//             for (auto it : mp)
//                 temp = max(temp, it.second + 1);
//             // +1 for the current point(point itself)

//             ans = max(temp, ans);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 1)
            return 1;

        int result = 2;
        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> mp;
            for (int j = 0; j < n; j++)
                if (j != i)
                    mp[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
                    // The function returns a numeric value between –pi and pi 
                    // representing the angle \theta of a (x, y) point and positive x-axis.

            for (auto [h, count] : mp)
                result = max(result, count + 1);
        }
        return result;
    }
};