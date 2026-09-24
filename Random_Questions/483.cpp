// 483. Smallest Good Base

// Given an integer n represented as a string, return the smallest good base of n.

// We call k >= 2 a good base of n, if all digits of n base k are 1's.

// Example 1:

// Input: n = "13"
// Output: "3"
// Explanation: 13 base 3 is 111.
// Example 2:

// Input: n = "4681"
// Output: "8"
// Explanation: 4681 base 8 is 11111.
// Example 3:

// Input: n = "1000000000000000000"
// Output: "999999999999999999"
// Explanation: 1000000000000000000 base 999999999999999999 is 11.

// Constraints:

// n is an integer in the range [3, 1018].
// n does not contain any leading zeros.

class Solution
{
public:
    string smallestGoodBase(string n)
    {
        long long N = stoll(n);

        // Maximum number of 1's is when base = 2
        int maxLen = 63;

        for (int len = maxLen; len >= 2; len--)
        {
            // N = 1 + k + k^2 + ... + k^(len-1)
            // Approximate k = N^(1/(len-1))
            long long k = pow((long double)N, 1.0L / (len - 1));

            // Check nearby values because floating point may have rounding
            // errors
            for (long long base = max(2LL, k - 1); base <= k + 1; base++)
            {
                __int128 sum = 1;
                __int128 power = 1;

                bool valid = true;

                for (int i = 1; i < len; i++)
                {
                    power *= base;

                    if (power > N)
                    {
                        valid = false;
                        break;
                    }

                    sum += power;

                    if (sum > N)
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid && sum == N)
                {
                    return to_string(base);
                }
            }
        }

        // If no representation with >= 3 ones exists,
        // N = 1 + (N-1), so base = N-1 gives "11".
        return to_string(N - 1);
    }
};
// TC-->O(log^2(N))  SC-->O(1)