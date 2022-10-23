class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);

        for (int i = 0; i < numRows; i++)
        {
            // for every row the number of cols will always be equal to the number of rows; resizing the empty vector to a size i+1
            ans[i].resize(i + 1);

            // first and last element is 1 either way
            ans[i][0] = ans[i][i] = 1;

            // traverse from the first col to the second last col
            for (int j = 1; j < i; j++)
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
                // 2,1  = 1,0 + 1,1
            }
        }
        return ans;
    }
};
