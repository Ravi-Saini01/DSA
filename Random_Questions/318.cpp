// 318. Maximum Product of Word Lengths

// Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

// Example 1:

// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".
// Example 2:

// Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4
// Explanation: The two words can be "ab", "cd".
// Example 3:

// Input: words = ["a","aa","aaa","aaaa"]
// Output: 0
// Explanation: No such pair of words.

// Constraints:

// 2 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// words[i] consists only of lowercase English letters.

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int n = words.size();

        unordered_set<char> set;
        int maxi = INT_MIN;

        for (int i = 0; i < n - 1; i++)
        {
            string str = words[i];
            for (char c : str)
            {
                set.insert(c);
            }

            for (int j = i + 1; j < n; j++)
            {
                string str1 = words[j];

                bool common = false;

                for (char ch : str1)
                {
                    if (set.find(ch) != set.end())
                    {
                        common = true;
                        break;
                    }
                }

                if (!common)
                {
                    int product = str.length() * str1.length();
                    maxi = max(maxi, product);
                }
            }
            set.clear();
        }
        return (maxi == INT_MIN) ? 0 : maxi;
    }
};
// TC-->O(N*M) where N is the number of words and M is the average length of the words.
// SC-->O(M) where M is the average length of the words.

// Approach 2: Using Bit Manipulation
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        vector<int> mask(n, 0);

        // build bitmask for each word
        for (int i = 0; i < n; i++)
        {
            for (char c : words[i])
            {
                mask[i] |= (1 << (c - 'a'));
            }
        }

        int ans = 0;

        // check every pair
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((mask[i] & mask[j]) == 0)
                {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }
};
// TC-->O(N^2) where N is the number of words.
// SC-->O(N) where N is the number of words.