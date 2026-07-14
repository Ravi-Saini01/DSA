// 394. Decode String

// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

// Constraints:

// 1 <= s.length <= 30
// s consists of lowercase English letters, digits, and square brackets '[]'.
// s is guaranteed to be a valid input.
// All the integers in s are in the range [1, 300].

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> stringStack;
        int k = 0;

        for (char c : s)
        {

            if (isdigit(c))
            {
                k = k * 10 + (c - '0');
                continue;
            }

            if (c == '[')
            {
                numStack.push(k);
                k = 0;
                stringStack.push("[");
                continue;
            }

            if (c != ']')
            {
                string temp(1, c);
                stringStack.push(temp);
                continue;
            }

            // Build the string inside the brackets
            string temp = "";
            while (!stringStack.empty() && stringStack.top() != "[")
            {
                temp = stringStack.top() + temp;
                stringStack.pop();
            }

            // Remove the "["
            stringStack.pop();

            // Repeat the string
            string replacement = "";
            int count = numStack.top();
            numStack.pop();

            for (int i = 0; i < count; i++)
            {
                replacement += temp;
            }

            // Push the expanded string back
            stringStack.push(replacement);
        }

        // Construct the final result
        string result = "";
        while (!stringStack.empty())
        {
            result = stringStack.top() + result;
            stringStack.pop();
        }

        return result;
    }
};
// TC-->O(n)
// SC-->O(n)