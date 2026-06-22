// 367. Valid Perfect Square

// Given a positive integer num, return true if num is a perfect square or false otherwise.

// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

// You must not use any built-in library function, such as sqrt.

// Example 1:

// Input: num = 16
// Output: true
// Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
// Example 2:

// Input: num = 14
// Output: false
// Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

// Constraints:

// 1 <= num <= 231 - 1

//(Using math)
class Solution
{
public:
    bool isPerfectSquare(int num)
    {

        for (int i = 1; (long)i * i <= num; i++)
        {
            if (i * i == num)
            {
                return true;
            }
        }
        return false;
    }
};
// TC: O(sqrt(n))

//(Using binary search)
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;
        int i = 1, j = num / 2;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;

            if ((long)mid * mid == num)
            {
                return true;
            }
            else if ((long)mid * mid < num)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return false;
    }
};
// TC--> O(log(n))