// 856. Score of Parentheses

// Given a balanced parentheses string s, return the score of the string.

// The score of a balanced parentheses string is based on the following rule:

// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.

// Example 1:

// Input: s = "()"
// Output: 1
// Example 2:

// Input: s = "(())"
// Output: 2
// Example 3:

// Input: s = "()()"
// Output: 2

// Constraints:

// 2 <= s.length <= 50
// s consists of only '(' and ')'.
// s is a balanced parentheses string.

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int n = s.length();
        vector<int> vec;

        int score = 0;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                vec.push_back(score);
                score = 0;
            }
            else
            {
                if (s[i - 1] == '(')
                { // we found inner most "()" -> +1 point
                    score = vec.back() + 1;
                }
                else
                {
                    // had content inside -> double it
                    score = vec.back() + (2 * score);
                }
                vec.pop_back();
            }
        }
        return score;
    }
};
// TC-->O(N)
// SC-->O(N)

// Approach-->2
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int score = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); i++)

        {
            if (s[i] == '(')
            {
                depth++;
            }
            else
            {
                depth--;

                if (s[i - 1] == '(')
                {
                    score += (1 << depth); // 2^depth
                }
            }
        }
        return score;
    }
};
// TC-->O(N)
// SC-->O(1)