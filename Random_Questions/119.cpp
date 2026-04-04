// 119. Pascal's Triangle II

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:

// Input: rowIndex = 0
// Output: [1]
// Example 3:

// Input: rowIndex = 1
// Output: [1,1]

// Constraints:

// 0 <= rowIndex <= 33

// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

// using extra space (same code for pascal's trangle)

class Solution
{
public:
    vector<int> getRow(int rowidx)
    {
        vector<vector<int>> result(rowidx + 1);

        for (int i = 0; i < rowidx + 1; i++)
        {
            result[i] = vector<int>(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }
        return result[rowidx];
    }
};

// TC-->O(N^2)
// SC-->O(n^2)

// Using Dp(1-D array)

class Solution
{
public:
    vector<int> getRow(int rowidx)
    {
        vector<int> pre;

        for (int i = 0; i < rowidx + 1; i++)
        {
            vector<int> curr(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                curr[j] = pre[j] + pre[j - 1];
            }
            swap(pre, curr);
        }
        return pre;
    }
};
// TC-->O(N^2)
// Sc-->O(rowidx);