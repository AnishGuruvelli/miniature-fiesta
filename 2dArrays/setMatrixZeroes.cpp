class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int xyz = INT_MAX - 1;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    int ind = i - 1;
                    while (ind >= 0)
                    {
                        if (matrix[ind][j] != 0)
                        {
                            matrix[ind][j] = xyz;
                        }
                        ind--;
                    }
                    ind = i + 1;
                    while (ind < rows)
                    {
                        if (matrix[ind][j] != 0)
                        {
                            matrix[ind][j] = xyz;
                        }
                        ind++;
                    }
                    ind = j - 1;
                    while (ind >= 0)
                    {
                        if (matrix[i][ind] != 0)
                        {
                            matrix[i][ind] = xyz;
                        }
                        ind--;
                    }
                    ind = j + 1;
                    while (ind < cols)
                    {
                        if (matrix[i][ind] != 0)
                        {
                            matrix[i][ind] = xyz;
                        }
                        ind++;
                    }
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0 || matrix[i][j] == xyz)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
