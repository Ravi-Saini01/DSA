// Palindrome String

// You are given a string s. Your task is to determine if the string is a palindrome. A string is considered a palindrome if it reads the same forwards and backwards.

// Examples :

// Input: s = "abba"
// Output: true
// Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.
// Input: s = "abc"
// Output: false
// Explanation: "abc" does not read the same forwards and backwards, so it is not a palindrome.
// Constraints:
// 1 ≤ s.size() ≤ 106
// The string s contains only lowercase english letters (a-z).

class Solution
{
public:
    bool check(int left, int right, string &s)
    {
        if (left >= right)
            return true;

        if (s[left] != s[right])
            return false;

        return check(left + 1, right - 1, s);
    }
    bool isPalindrome(string &s)
    {
        // code here
        return check(0, s.length() - 1, s);
    }
};