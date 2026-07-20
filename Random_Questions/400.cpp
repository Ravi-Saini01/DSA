// 400. Nth Digit

// Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

// Example 1:

// Input: n = 3
// Output: 3
// Example 2:

// Input: n = 11
// Output: 0
// Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

// Constraints:

// 1 <= n <= 231 - 1

class Solution
{
public:
    int findNthDigit(int n)
    {
        long long digitLength = 1;
        long long count = 9;
        long long start = 1;

        // Find the range containing the nth digit
        while (n > digitLength * count)
        {
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        // Find the actual number
        start += (n - 1) / digitLength;

        // Convert number to string and get the required digit
        string s = to_string(start);
        return s[(n - 1) % digitLength] - '0';
    }
};
// Tc-->O(log n) and Sc-->O(1)