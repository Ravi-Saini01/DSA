// 329. Longest Increasing Path in a Matrix

// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

// Example 1:

// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:

// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
// Example 3:

// Input: matrix = [[1]]
// Output: 1

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1

class Solution
{
public:
    int dfs(vector<vector<int>> &mat, int i, int j, int m, int n,
            vector<vector<int>> &dp)
    {
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        if (dp[i][j] > 1)
            return dp[i][j];
        for (auto [a, b] : dir)
        {
            int x = a + i, y = b + j;
            if (x >= 0 && y >= 0 && x < m && y < n && mat[i][j] < mat[x][y])
            {
                dp[i][j] = max(dp[i][j], 1 + dfs(mat, x, y, m, n, dp));
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>> &mat)
    {
        int i, j, m = mat.size(), n = mat[0].size(), ans = 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dp[i][j] == 1)
                    ans = max(ans, dfs(mat, i, j, m, n, dp));
            }
        }
        return ans;
    }
};
// TC--> O(m*n)
// SC--> O(m*n)