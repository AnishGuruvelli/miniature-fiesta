class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;

        sort(points.begin(), points.end());

        // for(int i=0;i<points.size();i++){
        //     for(int j=0;j<points[0].size();j++){
        //         cout<<points[i][j]<<" ";
        //     }
        // }

        int arrows = 0;
        int lastpoint = INT_MIN;

        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] > lastpoint)
            {
                lastpoint = points[i][1];
                arrows++;
            }
            lastpoint = min(lastpoint, points[i][1]);
        }
        return arrows;
    }
};

// Ex: [[10,16],[2,8],[1,6],[7,12]]
// 1 6 2 8 7 12 10 16