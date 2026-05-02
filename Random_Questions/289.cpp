// 289. Game of Life

// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

// Given the current state of the board, update the board to reflect its next state.

// Note that you do not need to return anything.

// Example 1:

// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
// Example 2:

// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.

class Solution
{
public:
    bool isValidNeighbor(int x, int y, vector<vector<int>> &board)
    {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        // for 8 neighbors
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1};

        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                int cnt_live_nei = 0;

                for (int i = 0; i < 8; i++)
                {
                    int curr_x = row + dx[i], curr_y = col + dy[i];

                    if (isValidNeighbor(curr_x, curr_y, board) &&
                        abs(board[curr_x][curr_y]) == 1)
                    {
                        cnt_live_nei++;
                    }
                }
                if (board[row][col] == 1 && (cnt_live_nei < 2 ||
                                             cnt_live_nei > 3))
                {
                    board[row][col] = -1;
                }

                if (board[row][col] == 0 && cnt_live_nei == 3)
                {
                    board[row][col] = 2;
                }
            }
        }
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (board[row][col] >= 1)
                {
                    board[row][col] = 1;
                }
                else
                {
                    board[row][col] = 0;
                }
            }
        }
    }
};
// TC-->O(m*n)