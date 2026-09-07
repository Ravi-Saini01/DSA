// 467. Unique Substrings in Wraparound String

// We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:

// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
// Given a string s, return the number of unique non-empty substrings of s are present in base.

// Example 1:

// Input: s = "a"
// Output: 1
// Explanation: Only the substring "a" of s is in base.
// Example 2:

// Input: s = "cac"
// Output: 2
// Explanation: There are two substrings ("a", "c") of s in base.
// Example 3:

// Input: s = "zab"
// Output: 6
// Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of s in base.

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        vector<int> maxLen(26, 0);

        int currLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i > 0 &&
                (s[i] - s[i - 1] == 1 || s[i - 1] == 'z' && s[i] == 'a'))
            {
                currLen++;
            }
            else
            {
                currLen = 1;
            }

            int idx = s[i] - 'a';

            // Keep only the longest valid substring ending at s[i].
            maxLen[idx] = max(maxLen[idx], currLen);
        }

        int ans = 0;
        for (int len : maxLen)
        {
            ans += len;
        }

        return ans;
    }
};
// TC-->O(N)