class Solution
{
public:
    bool dfs(vector<vector<char>> &board, int i, int j, int m, int n, vector<vector<char>> &dp)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        char alpha = board[i][j];
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector < vector<char> dp(m vector<int>(n, -1));
        return dfs(board, 0, 0, m, n, dp);
    }
};

// Solution 01:
class Solution
{
public:
    bool search(int index, int x, int y, vector<vector<char>> &board, string &word)
    {
        if (index == word.size())
            return true;

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '.')
            return false;

        if (board[x][y] != word[index])
            return false;

        char temp = board[x][y];
        board[x][y] = '.';
        if (search(index + 1, x - 1, y, board, word) || search(index + 1, x + 1, y, board, word) || search(index + 1, x, y - 1, board, word) || search(index + 1, x, y + 1, board, word))
            return true;

        board[x][y] = temp;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (search(0, i, j, board, word))
                    return true;
        return false;
    }
};

/* Time Complexity : O(n*m*4^k)
   Space Complexity : O(k) ; k : length of word */

class Solution
{
public:
    bool search(int i, int j, int n, int m, vector<vector<char>> &board, string &word, int k)
    {
        // base cases
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
            return false;

        char ch = board[i][j];
        board[i][j] = '#'; // hashing the word visited, for avoiding repeatation problems

        // Recursive relations - exploring all four directions

        bool op1 = search(i + 1, j, n, m, board, word, k + 1);
        bool op2 = search(i - 1, j, n, m, board, word, k + 1);
        bool op3 = search(i, j + 1, n, m, board, word, k + 1);
        bool op4 = search(i, j - 1, n, m, board, word, k + 1);
        
        if (op1 || op2 || op3 || op4)
            return true;

        board[i][j] = ch; // backtracking

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0])
                    if (search(i, j, n, m, board, word, 0))
                        return true;

        return false;
    }
};