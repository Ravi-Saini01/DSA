// 221. Maximal Square

// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:

// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.

// Approach--> 1 (Recursive)
class Solution
{
public:
    int solve(int i, int j, vector<vector<char>> &matrix, int m, int n)
    {
        if (i >= m || j >= n)
            return 0;

        if (matrix[i][j] == '0')
            return 0;

        int right = solve(i, j + 1, matrix, m, n);
        int dia = solve(i + 1, j + 1, matrix, m, n);
        int down = solve(i + 1, j, matrix, m, n);

        return 1 + min(right, min(dia, down));
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int side = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    side = max(side, solve(i, j, matrix, m, n));
                }
            }
        }
        return side * side;
    }
};
// TC-->O(m*n*3^(m+n))

// Approach-->2 (Memoization)
class Solution
{
public:
    int solve(int i, int j, vector<vector<char>> &matrix, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return 0;

        if (matrix[i][j] == '0')
            return dp[i][j] = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j + 1, matrix, m, n, dp);
        int dia = solve(i + 1, j + 1, matrix, m, n, dp);
        int down = solve(i + 1, j, matrix, m, n, dp);

        return dp[i][j] = 1 + min(right, min(dia, down));
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int side = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    side = max(side, solve(i, j, matrix, m, n, dp));
                }
            }
        }
        return side * side;
    }
};
// TC-->O(m*n)
// SC-->O(m*n)+rss

// Approach --> 3(Bottom up)

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // extra row & col to avoid bounds checking
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int side = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    int right = dp[i][j + 1];
                    int dia = dp[i + 1][j + 1];
                    int down = dp[i + 1][j];

                    dp[i][j] = 1 + min({right, dia, down});
                    side = max(side, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return side * side;
    }
};
// TC-->O(m*n)
// SC-->O(m*n)
