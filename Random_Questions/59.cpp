// 59. Spiral Matrix II

// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:

// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 20

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        int srow = 0, scol = 0, erow = n - 1, ecol = n - 1;
        vector<vector<int>> mat(n, vector<int>(n));
        int num = 1;

        while (srow <= erow && scol <= ecol)
        {
            // top
            for (int j = scol; j <= ecol; j++)
                mat[srow][j] = num++;

            srow++;

            // right
            if (srow <= erow)
            {
                for (int i = srow; i <= erow; i++)
                    mat[i][ecol] = num++;
                ecol--;
            }

            // bottom
            if (srow <= erow)
            {
                for (int j = ecol; j >= scol; j--)
                    mat[erow][j] = num++;
                erow--;
            }

            // left
            if (scol <= ecol)
            {
                for (int i = erow; i >= srow; i--)
                    mat[i][scol] = num++;
                scol++;
            }
        }
        return mat;
    }
};