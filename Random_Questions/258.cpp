// 258. Add Digits

// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

// Example 1:

// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2
// Since 2 has only one digit, return it.
// Example 2:

// Input: num = 0
// Output: 0

// Constraints:

// 0 <= num <= 231 - 1

class Solution
{
public:
    int addDigits(int n)
    {

        if (n == 0)
            return 0;

        if (n < 10)
            return n;

        int ans = 0, digit = 0;

        while (true)
        {

            digit += n % 10;
            n /= 10;

            if (digit < 10 && n == 0)
            {
                ans = digit;
                break;
            }
            if (n == 0)
            {
                n = digit;
                digit = 0;
            }
        }
        return ans;
    }
};
// TC-->O(log(n))