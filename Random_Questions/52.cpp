// 52. N-Queens II

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1

// Constraints:

// 1 <= n <= 9

// (Approach-->1)(using backtracking and recursion)
class Solution
{
public:
    void nqueens(vector<string> &board, int row, int n,
                 vector<vector<string>> &ans)
    {
        if (row == n)
        {
            ans.push_back({board});
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (issafe(board, row, j, n))
            {
                board[row][j] = 'Q';
                nqueens(board, row + 1, n, ans);

                board[row][j] = '.';
            }
        }
    }
    bool issafe(vector<string> &board, int row, int col, int n)
    {
        // horizontlly
        for (int j = 0; j < n; j++)
        {
            if (board[row][j] == 'Q')
            {
                return false;
            }
        }
        // vertically
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        // left dignoal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        // right dignoal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    int totalNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nqueens(board, 0, n, ans);
        return ans.size();
    }
};

// TC-->(N!)

// (Approach-->2)(using backtracking and vectors)

class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<bool> col(n, true);
        vector<bool> antiD(2 * n - 1, true);
        vector<bool> mainD(2 * n - 1, true);
        vector<int> row(n, 0);
        int count = 0;
        dfs(0, row, col, mainD, antiD, count);
        return count;
    }
    void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool> &mainD,
             vector<bool> &antiD, int &count)
    {
        if (i == row.size())
        { // filled all the rows with queens
            count++;
            return;
        }
        for (int j = 0; j < col.size(); j++)
        {
            if (col[j] && mainD[i + j] && antiD[i + col.size() - 1 - j])
            {
                row[i] = j;
                col[j] = mainD[i + j] = antiD[i + col.size() - 1 - j] = false;
                dfs(i + 1, row, col, mainD, antiD, count);
                // backtracking
                col[j] = mainD[i + j] = antiD[i + col.size() - 1 - j] = true;
            }
        }
    }
};

//TC-->(N!)
