// 434. Number of Segments in a String

// Given a string s, return the number of segments in the string.

// A segment is defined to be a contiguous sequence of non-space characters.

// Example 1:

// Input: s = "Hello, my name is John"
// Output: 5
// Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
// Example 2:

// Input: s = "Hello"
// Output: 1

// Constraints:

// 0 <= s.length <= 300
// s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
// The only space character in s is ' '.

class Solution
{
public:
    int countSegments(string s)
    {
        int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
            {
                cnt++;
            }
        }
        return cnt;
    }
};
// TC-->O(N)