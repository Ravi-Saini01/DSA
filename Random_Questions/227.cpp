// 227. Basic Calculator II

// Given a string s which represents an expression, evaluate this expression and return its value.

// The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:

// Input: s = "3+2*2"
// Output: 7
// Example 2:

// Input: s = " 3/2 "
// Output: 1
// Example 3:

// Input: s = " 3+5 / 2 "
// Output: 5

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
// s represents a valid expression.
// All the integers in the expression are non-negative integers in the range [0, 231 - 1].
// The answer is guaranteed to fit in a 32-bit integer.

class Solution
{
public:
    int calculate(string s)
    {
        int len = s.length();
        stack<int> st;
        long long curr = 0;
        char op = '+';

        for (int i = 0; i < len; i++)
        {
            if (isdigit(s[i]))
            {
                curr = curr * 10 + s[i] - '0';
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == len - 1)
            {
                if (op == '+')
                {
                    st.push(curr);
                }
                else if (op == '-')
                {
                    st.push(-curr);
                }
                else if (op == '*')
                {
                    int ans = st.top() * curr;
                    st.pop();
                    st.push(ans);
                }
                else if (op == '/')
                {
                    int ans = st.top() / curr;
                    st.pop();
                    st.push(ans);
                }
                op = s[i];
                curr = 0;
            }
        }

        // calculate sum of all stack element
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
// TC-->O(N)