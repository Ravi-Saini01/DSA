// GCD of two numbers

// Given two positive integers a and b, find GCD of a and b.

// Note: Don't use the inbuilt gcd function

// Examples:

// Input: a = 20, b = 28
// Output: 4
// Explanation: GCD of 20 and 28 is 4
// Input: a = 60, b = 36
// Output: 12
// Explanation: GCD of 60 and 36 is 12
// Constraints:
// 1 ≤ a, b ≤ 109

// Euclidean Algorithm(for finding GCD)

class Solution
{
    int gcd(int a, int b)
    {
        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a %= b;
            }
            else
            {
                b %= a;
            }
        }
        if (a == 0)
        {
            return a;
        }

        return b;
    }
};

// Time Complexity: O(log(min(a, b)))