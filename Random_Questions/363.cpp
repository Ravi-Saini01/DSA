// Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

// It is guaranteed that there will be a rectangle with a sum no larger than k.

// Example 1:

// Input: matrix = [[1,0,1],[0,-2,3]], k = 2
// Output: 2
// Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
// Example 2:

// Input: matrix = [[2,2,-1]], k = 3
// Output: 3

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -100 <= matrix[i][j] <= 100
// -105 <= k <= 105

// // Follow up: What if the number of rows is much larger than the number of columns?

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // If rows > columns, transpose to optimize
        bool transpose = (m > n);

        vector<vector<int>> mat;

        if (transpose)
        {
            mat.assign(n, vector<int>(m));

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mat[j][i] = matrix[i][j];
                }
            }

            swap(m, n);
        }
        else
        {
            mat = matrix;
        }

        int ans = INT_MIN;

        // Fix left boundary
        for (int left = 0; left < n; left++)
        {

            vector<int> rowSum(m, 0);

            // Fix right boundary
            for (int right = left; right < n; right++)
            {

                // Build compressed array
                for (int row = 0; row < m; row++)
                {
                    rowSum[row] += mat[row][right];
                }

                // Find max subarray sum <= k
                set<int> prefixSet;
                prefixSet.insert(0);

                int prefix = 0;

                for (int x : rowSum)
                {
                    prefix += x;

                    // Need smallest prefix >= prefix-k
                    auto it = prefixSet.lower_bound(prefix - k);

                    if (it != prefixSet.end())
                    {
                        ans = max(ans, prefix - *it);
                    }

                    prefixSet.insert(prefix);
                }
            }
        }

        return ans;
    }
};

// TC-->O(m^2*nlog(n))
