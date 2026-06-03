// 326. Power of Three

// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).

// Constraints:

// -231 <= n <= 231 - 1

// Follow up: Could you solve it without loops/recursion?

// Approach -->1 (Using loop)

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0 || n < 0)
            return false;

        if (n == 1)
            return true;

        if (n % 3 != 0)
            return false;

        while (true)
        {
            if (n % 3 == 0)
            {
                n /= 3;
                if (n == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};
// TC--> O(logn) due to division by 3 in each iteration
// SC--> O(1) as we are using constant space

// Approach -->2 (Using logarithmic properties)
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        double x = log10(n) / log10(3);

        return x == (int)x;
    }
};
// TC--> O(1) as we are using logarithmic properties
// SC--> O(1) as we are using constant space

// Approach -->3 (Using maximum power of 3 within integer range)
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        int x = pow(3, 19);

        return x % n == 0;
    }
};
// TC--> O(1) as we are using constant time operations