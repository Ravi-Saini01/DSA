// Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

// Return the maximum product you can get.

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.
// Example 2:

// Input: n = 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

// Constraints:

// 2 <= n <= 58

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 1)
            return 1;

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int result = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            int prod = i * max(n - i, solve(n - i, dp));
            result = max(result, prod);
        }

        return dp[n] = result;
    }
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
// TC-->O(n^2)
// SC-->O(n)