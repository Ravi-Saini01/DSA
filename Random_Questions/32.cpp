// 32. Longest Valid Parentheses

// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // bas case
        int len = s.length();
        if (len == 0 || len == 1)
            return 0;

        int l = 0, r = 0, m = 0;

        // loop from 0 to len
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                l++;
            }
            else
            {
                r++;
            }

            if (l == r)
            {
                m = max(m, l + r);
            }
            else if (r > l)
            {
                l = 0;
                r = 0;
            }
        }

        l = 0, r = 0;
        // loop from len to 0
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                l++;
            }
            else
            {
                r++;
            }

            if (l == r)
            {
                m = max(m, l + r);
            }
            else if (l > r)
            {
                l = 0;
                r = 0;
            }
        }
        return m;
    }
};