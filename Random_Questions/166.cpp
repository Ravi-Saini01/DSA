// 166. Fraction to Recurring Decimal

// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

// Note that if the fraction can be represented as a finite length string, you must return it.

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"

// Constraints:

// -231 <= numerator, denominator <= 231 - 1
// denominator != 0

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        string result;

        if ((long long)numerator * (long long)denominator < 0)
        {
            result += "-";
        }

        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);

        long long integerDiv = absNumerator / absDenominator;

        result += to_string(integerDiv); // log10(integerDiv)

        long long remain = absNumerator % absDenominator;
        if (remain == 0)
        {
            return result;
        }

        result += '.';

        unordered_map<int, int> mp;
        // 0 <= remain < denominator
        // O(denominator + length)
        while (remain != 0)
        {
            if (mp.count(remain))
            {
                result.insert(mp[remain], "("); // O(length)
                result += ")";
                break;
            }

            mp[remain] = result.length();

            remain *= 10;
            int digit = remain / absDenominator;
            result += to_string(digit); // O(1)

            remain = remain % absDenominator;
        }

        return result;
    }
};
// TC-->(denominator)