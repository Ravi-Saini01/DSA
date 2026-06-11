// 336. Palindrome Pairs

// You are given a 0-indexed array of unique strings words.

// A palindrome pair is a pair of integers (i, j) such that:

// 0 <= i, j < words.length,
// i != j, and
// words[i] + words[j] (the concatenation of the two strings) is a palindrome.
// Return an array of all the palindrome pairs of words.

// You must write an algorithm with O(sum of words[i].length) runtime complexity.

// Example 1:

// Input: words = ["abcd","dcba","lls","s","sssll"]
// Output: [[0,1],[1,0],[3,2],[2,4]]
// Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
// Example 2:

// Input: words = ["bat","tab","cat"]
// Output: [[0,1],[1,0]]
// Explanation: The palindromes are ["battab","tabbat"]
// Example 3:

// Input: words = ["a",""]
// Output: [[0,1],[1,0]]
// Explanation: The palindromes are ["a","a"]

// Constraints:

// 1 <= words.length <= 5000
// 0 <= words[i].length <= 300
// words[i] consists of lowercase English letters.

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> ans;
        int n = words.size();
        if (n < 2)
            return ans;
        unordered_map<string, int> m;
        for (int i = 0; i < n; ++i)
        {

            auto s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= words[i].size(); ++j)
            {
                string st1 = words[i].substr(0, j); // prefix
                string st2 = words[i].substr(j);    // sufix

                if (m.count(st1) && isPalindrome(st2) && m[st1] != i)
                {
                    ans.push_back({i, m[st1]});
                }

                if (!st1.empty() && m.count(st2) && isPalindrome(st1) &&
                    m[st2] != i)
                {
                    ans.push_back({m[st2], i});
                }
            }
        }
        return ans;
    }
};
// TC-->O(n*k^2)
// SC-->O(n*k)