// 479. Largest Palindrome Product

// Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.

// Example 1:

// Input: n = 2
// Output: 987
// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
// Example 2:

// Input: n = 1
// Output: 9

// Constraints:

// 1 <= n <= 8

class Solution
{
public:
    int largestPalindrome(int n)
    {
        if (n == 1)
            return 9;

        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);

        // Generate palindromes by mirroring the first half
        for (int left = upper; left >= lower; --left)
        {
            string s = to_string(left);
            string rev = s;
            reverse(rev.begin(), rev.end());

            // Create an even-length palindrome
            long long pal = stoll(s + rev);

            // Try to factorize the palindrome
            for (long long i = upper; i >= lower; --i)
            {
                if (i * i < pal)
                    break;

                if (pal % i == 0)
                {
                    long long other = pal / i;

                    if (other >= lower && other <= upper)
                        return pal % 1337;
                }
            }
        }

        return 0;
    }
};
// TC-->O(10^2n)