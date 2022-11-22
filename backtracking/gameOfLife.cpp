class Solution
{
public:
    int countLiveN(vector<vector<int>> &curr, int row, int col, int rows, int cols)
    {
        int numberOfLiveNeighbors = 0;

        // up
        if (row > 0)
            if (curr[row - 1][col] == 1)
                numberOfLiveNeighbors++;
        // down
        if (row < rows - 1)
            if (curr[row + 1][col] == 1)
                numberOfLiveNeighbors++;
        // left
        if (col > 0)
            if (curr[row][col - 1] == 1)
                numberOfLiveNeighbors++;
        // right
        if (col < cols - 1)
            if (curr[row][col + 1] == 1)
                numberOfLiveNeighbors++;
        // top-left
        if (row > 0 && col > 0)
            if (curr[row - 1][col - 1] == 1)
                numberOfLiveNeighbors++;
        // top-right
        if (row > 0 && col < cols - 1)
            if (curr[row - 1][col + 1] == 1)
                numberOfLiveNeighbors++;
        // bottom-left
        if (row < rows - 1 && col > 0)
            if (curr[row + 1][col - 1] == 1)
                numberOfLiveNeighbors++;
        // bottom-right
        if (row < rows - 1 && col < cols - 1)
            if (curr[row + 1][col + 1] == 1)
                numberOfLiveNeighbors++;

        return numberOfLiveNeighbors;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> curr = board;
        int rows = board.size();
        int cols = board[0].size();
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int liveN = countLiveN(curr, row, col, rows, cols);
                if (board[row][col] == 0)
                {
                    if (liveN == 3)
                    {
                        board[row][col] = 1;
                    }
                }

                else if (board[row][col] == 1)
                {
                    if (liveN < 2 || liveN > 3)
                    {
                        board[row][col] = 0;
                    }
                }
            }
        }
    }
};

/*
int getLiveNeighbours(vector<vector<int>> &curr, int i, int j, int m, int n)
{
    int liveNeighbours = 0;
    if (i > 0)
    {
        // check the upper neighbour
        if (curr[i - 1][j] == 1)
            liveNeighbours++;
    }
    if (i < m - 1)
    {
        // check the lower neighbour
        if (curr[i + 1][j] == 1)
            liveNeighbours++;
    }
    if (j > 0)
    {
        // check the left neighbour
        if (curr[i][j - 1] == 1)
            liveNeighbours++;
    }
    if (j < n - 1)
    {
        // check the right neighbour
        if (curr[i][j + 1] == 1)
            liveNeighbours++;
    }

    if (i > 0 && j > 0)
    {
        if (curr[i - 1][j - 1] == 1)
            liveNeighbours++;
    }
    if (i > 0 && j < n - 1)
    {
        if (curr[i - 1][j + 1] == 1)
            liveNeighbours++;
    }
    if (i < m - 1 && j > 0)
    {
        if (curr[i + 1][j - 1] == 1)
            liveNeighbours++;
    }
    if (i < m - 1 && j < n - 1)
    {
        if (curr[i + 1][j + 1] == 1)
            liveNeighbours++;
    }
    return liveNeighbours;
}
void gameOfLife(vector<vector<int>> &board)
{
    vector<vector<int>> curr = board;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ln = getLiveNeighbours(curr, i, j, m, n);
            if (board[i][j] == 0)
            {
                // currently dead
                // can become alive if has exactly three live neighbours
                if (ln == 3)
                {
                    board[i][j] = 1;
                }
            }
            else if (board[i][j] == 1)
            {
                //<2 -> die
                //==2 || ==3 live
                //>3 ->die
                if (ln < 2 || ln > 3)
                {
                    board[i][j] = 0;
                }
            }
        }
    }
}
*/

// https://leetcode.com/problems/game-of-life/solutions/1225591/c-two-approaches-with-intuition-faster-than-100/