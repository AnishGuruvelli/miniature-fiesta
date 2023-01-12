// https://www.youtube.com/watch?v=9wEwqNdOAVQ&list=PLDzeHZWIZsTq8KwpV5ipe5-ncApOTEL9k&index=2
// https://www.youtube.com/watch?v=i05Ju7AftcM

class Solution
{
public:
	void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
	{
		vector<int> temp;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp.push_back(board[i][j]);

		ans.push_back(temp);
	}

	bool isSafe(int x, int y, vector<vector<int>> &board, int n)
	{
		int row = x;
		int col = y;
		// check for same row
		while (y >= 0)
		{
			if (board[x][y] == 1)
				return false;
			y--;
		}

		// no need to check for col

		// check for diagonal upwards
		row = x;
		col = y;
		while (x >= 0 && y >= 0)
		{
			if (board[x][y] == 1)
				return false;
			x--;
			y--;
		}

		// check for diagonal donwnwards
		row = x;
		col = y;
		while (x < n && y >= 0)
		{
			if (board[x][y] == 1)
				return false;
			x++;
			y--;
		}

		return true;
	}

	void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
	{
		// base case
		if (col == n)
		{
			addSolution(board, ans, n);
			return;
		}

		for (int row = 0; row < n; row++)
			if (isSafe(row, col, board, n))
			{
				board[row][col] = 1;
				addSolution(board, ans, n);
				board[row][col] = 0;
			}
	}

	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<int>> board(n, vector<int>(n, 0));
		vector<vector<int>> ans;

		solve(0, ans, board, n);

		return ans;
	}
};