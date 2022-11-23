class Solution
{
public:
    bool isValid(vector<vector<char>> &board, int row, int col, int c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;

            /// at 24:17: https://www.youtube.com/watch?v=FWAIf_EVUKE
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int temp = board[i][j];
                    board[i][j] = '*';
                    if (!isValid(board, i, j, temp))
                        return false;
                    board[i][j] = temp;
                }
            }
        }
        return true;
    }
};
