// 397. Integer Replacement

// Given a positive integer n, you can apply one of the following operations:

// If n is even, replace n with n / 2.
// If n is odd, replace n with either n + 1 or n - 1.
// Return the minimum number of operations needed for n to become 1.

// Example 1:

// Input: n = 8
// Output: 3
// Explanation: 8 -> 4 -> 2 -> 1
// Example 2:

// Input: n = 7
// Output: 4
// Explanation: 7 -> 8 -> 4 -> 2 -> 1
// or 7 -> 6 -> 3 -> 2 -> 1
// Example 3:

// Input: n = 4
// Output: 2

// Constraints:

// 1 <= n <= 231 - 1

// Approach-->1 (Using Recursion)
class Solution
{
public:
    int solve(long long n)
    {
        if (n == 1)
            return 0;

        if (n % 2 == 0)
        {
            return 1 + solve(n / 2);
        }

        return 1 + min(solve(n - 1), solve(n + 1));
    }
    int integerReplacement(int n) { return solve(n); }
};
// TC-->O(2^n)
// SC-->RSS

// Approach-->2 (Using Recursion + Memoization)
class Solution
{
public:
    unordered_map<long long, int> dp;
    int solve(long long n)
    {
        if (n == 1)
            return 0;

        if (dp.count(n))
            return dp[n];

        if (n % 2 == 0)
        {
            return dp[n] = 1 + solve(n / 2);
        }

        return dp[n] = 1 + min(solve(n - 1), solve(n + 1));
    }
    int integerReplacement(int n) { return solve(n); }
};
// TC-->O(logn)^2
// TC-->O(logn)^2

// Approach-->3 (Using Iteration)
class Solution
{
public:
    int integerReplacement(int n)
    {
        long long x = n; // avoid overflow for INT_MAX
        int ans = 0;

        while (x != 1)
        {
            if ((x & 1) == 0)
            {
                x >>= 1;
            }
            else
            {
                if (x == 3 || (x & 3) == 1)
                    x--;
                else
                    x++;
            }
            ans++;
        }

        return ans;
    }
};
// TC-->O(logn)
// SC-->O(1)