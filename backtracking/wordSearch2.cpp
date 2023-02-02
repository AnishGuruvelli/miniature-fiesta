// WAY TOO MUCH TIME CONSUMING

class Solution
{
public:
    bool solve(int i, int j, int n, int m, vector<vector<char>> &board, string &word, int index)
    {
        if (word.size() == index)
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index])
            return false;

        char ch = board[i][j];
        board[i][j] = '#';
        bool op1 = solve(i + 1, j, n, m, board, word, index + 1);
        bool op2 = solve(i, j + 1, n, m, board, word, index + 1);
        bool op3 = solve(i - 1, j, n, m, board, word, index + 1);
        bool op4 = solve(i, j - 1, n, m, board, word, index + 1);
        board[i][j] = ch;
        if (op1 || op2 || op3 || op4)
            return true;
        return false;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        // vector<string> ans;
        // int n = board.size(), m = board[0].size();
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < m; j++)
        //         for (auto word : words)
        //             if (board[i][j] == word[0])
        //                 if (solve(i, j, n, m, board, word, 0))
        //                     ans.push_back(word);
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        // return ans;

        /*
        Duplicates: The line ans.erase(unique(ans.begin(), ans.end()), ans.end()); tries to remove duplicates from the answer vector, but the unique function only removes adjacent duplicates, not all duplicates.
        To remove duplicates from a vector in C++, you can use the std::set container. The set container stores only unique elements and automatically removes duplicates. Here's an example of how you could use a set in the given code:
        */

        set<string> ans;
        int n = board.size(), m = board[0].size();
        for (auto word : words)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (board[i][j] == word[0])
                        if (solve(i, j, n, m, board, word, 0))
                            ans.insert(word);

        return vector<string>(ans.begin(), ans.end());
    }
};

// STILL TIME LIMIT EXCEEDED

class Solution
{
public:
    bool solve(int i, int j, int n, int m, vector<vector<char>> &board, string &word, int index, vector<vector<bool>> &visited)
    {
        if (word.size() == index)
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || board[i][j] != word[index])
            return false;

        visited[i][j] = true;
        bool op1 = solve(i + 1, j, n, m, board, word, index + 1, visited);
        bool op2 = solve(i, j + 1, n, m, board, word, index + 1, visited);
        bool op3 = solve(i - 1, j, n, m, board, word, index + 1, visited);
        bool op4 = solve(i, j - 1, n, m, board, word, index + 1, visited);
        visited[i][j] = false;
        if (op1 || op2 || op3 || op4)
            return true;
        return false;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        set<string> ans;
        int n = board.size(), m = board[0].size();
        for (auto word : words)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == word[0])
                    {
                        vector<vector<bool>> visited(n, vector<bool>(m, false));
                        if (solve(i, j, n, m, board, word, 0, visited))
                        {
                            ans.insert(word);
                            break;
                        }
                    }
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};

// PERFECT CODE

class Solution
{
    unordered_set<string> mp;
    vector<string> ans;
    // stores the maximum length of string
    int mx;

    void dfs(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visit, string &word)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        if (visit[i][j] || word.length() >= mx)
            return;

        word.push_back(board[i][j]);

        // if mp contains the word, it is added to the answer
        // also, word is removed imediately from the map, to prevent duplicates
        // in answer
        if (mp.count(word))
        {
            ans.push_back(word);
            mp.erase(word);
        }

        visit[i][j] = true;
        dfs(board, i + 1, j, visit, word);
        dfs(board, i - 1, j, visit, word);
        dfs(board, i, j + 1, visit, word);
        dfs(board, i, j - 1, visit, word);
        visit[i][j] = false;

        word.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        mx = 0;

        for (auto word : words)
        {
            mp.insert(word);
            int n = word.size();
            mx = max(mx, n);
            cout << mx << endl;
        }

        string s = "";
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, visit, s);

        return ans;
    }
};