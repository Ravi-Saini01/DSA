// 395. Longest Substring with At Least K Repeating Characters

// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

// if no such substring exists, return 0.

// Example 1:

// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:

// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

// Constraints:

// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 105

class Solution
{
public:
    int solve(string &s, int left, int right, int k)
    {
        if (right - left < k)
            return 0;

        vector<int> freq(26, 0);

        // Count frequency in current substring
        for (int i = left; i < right; i++)
            freq[s[i] - 'a']++;

        // Find an invalid character
        for (int mid = left; mid < right; mid++)
        {
            if (freq[s[mid] - 'a'] >= k)
                continue;

            int next = mid + 1;
            while (next < right && freq[s[next] - 'a'] < k)
                next++;

            return max(solve(s, left, mid, k), solve(s, next, right, k));
        }

        // All characters appear at least k times
        return right - left;
    }
    int longestSubstring(string s, int k) { return solve(s, 0, s.size(), k); }
};
// Tc-->O(n^2)
// SC-->O(n)