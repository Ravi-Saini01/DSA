// 279. Perfect Squares

// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

// Constraints:

// 1 <= n <= 104

// Approach-->1 (Recursion)
class Solution
{
public:
    int helper(int n)
    {
        if (n == 0)
            return 0;

        int mincnt = INT_MAX;

        for (int i = 1; i * i <= n; i++)
        {
            int result = 1 + helper(n - i * i);
            mincnt = min(mincnt, result);
        }
        return mincnt;
    }

    int numSquares(int n)
    {

        return helper(n);
    }
};

// Approach-->2 (using Memo)
class Solution
{
public:
    int helper(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        int mincnt = INT_MAX;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++)
        {
            int result = 1 + helper(n - i * i, dp);
            mincnt = min(mincnt, result);
        }
        return dp[n] = mincnt;
    }

    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};
// TC-->O(N)
// SC-->O(N)

// Approach-->3 (Using Bottom up)
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};
// TC-->O(N)
// SC-->O(N)