// 405. Convert a Number to Hexadecimal

// Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

// All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

// Note: You are not allowed to use any built-in library method to directly solve this problem.

// Example 1:

// Input: num = 26
// Output: "1a"
// Example 2:

// Input: num = -1
// Output: "ffffffff"

// Constraints:

// -231 <= num <= 231 - 1

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return to_string(0);

        string digits = "0123456789abcdef";
        unsigned int n = num;

        string res = "";

        while (n > 0)
        {
            int rem = n % 16;
            res += digits[rem];
            n /= 16;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// TC--> O(log(num)) where num is the input number. The while loop runs until n becomes 0, and in each iteration, we divide n by 16,
// which reduces the number of digits in the hexadecimal representation. Therefore, the time complexity is logarithmic with respect to
// the input number.