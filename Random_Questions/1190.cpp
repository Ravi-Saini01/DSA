// 1190. Reverse Substrings Between Each Pair of Parentheses

// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

// Example 1:

// Input: s = "(abcd)"
// Output: "dcba"
// Example 2:

// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
// Example 3:

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

// Constraints:

// 1 <= s.length <= 2000
// s only contains lower case English characters and parentheses.
// It is guaranteed that all parentheses are balanced.

class Solution
{
public:
    string reverseParentheses(string s)
    {
        int n = s.length();
        stack<int> openbracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                openbracket.push(i);
            }
            else if (s[i] == ')')
            {
                int j = openbracket.top();
                openbracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }
        // Second pass: Build the result string
        string res;
        int direction = 1;

        for (int i = 0; i < n; i += direction)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                i = door[i];
                direction = -direction;
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};
// TC-->O(N)