// Input
// mat = [[1,2,3,4]]
// r = 2
// c = 2
// 26 / 57 testcases passed
// Output
// [[1,2],[2,3]]
// Expected
// [[1,2],[3,4]]

// class Solution
// {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
//     {
//         vector<int> v;
//         int m = mat.size(), n = mat[0].size();

//         if (m * n != r * c)
//             return mat;

//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 v.push_back(mat[i][j]);

//         vector<vector<int>> p;
//         for (int i = 0; i < r; i++)
//         {
//             vector<int> q;
//             for (int j = 0; j < c; j++)
//                 q.push_back(v[i + j]);
//             // but this will traverse like : 0 0 ; 0 1 ; 1 0 ; 1 1
//             p.push_back(q);
//         }
//         return p;
//     }
// };

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int m = nums.size(), n = nums[0].size();

        if (m * n != r * c)
            return nums;

        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int k = i * n + j;
                res[k / c][k % c] = nums[i][j];
            }

        return res;
    }
};