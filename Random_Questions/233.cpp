// 233. Number of Digit One

// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

// Example 1:

// Input: n = 13
// Output: 6
// Example 2:

// Input: n = 0
// Output: 0

// Constraints:

// 0 <= n <= 10^9

class Solution
{
public:
    int countDigitOne(int n)
    {
        if (n == 0)
            return 0;

        long long ans = 0;

        for (long long i = 1; i <= n; i *= 10)
        {
            long long div = i * 10;
            long long q = n / div;
            long long rem = n % div;

            ans += q * i;

            if (rem >= i)
            {
                ans += min(rem - i + 1, i);
            }
        }

        return ans;
    }
};
// TC-->O(LOG(base 10)(n))