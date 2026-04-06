// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []

// Constraints:

// 1 <= s.length <= 20
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 10
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.
// Input is generated in a way that the length of the answer doesn't exceed 105.

// Approach-->1(Using recursion)

class Solution
{
public:
    vector<string> result;
    unordered_set<string> dict;

    void solve(int i, string &currSentence, string &s)
    {
        if (i >= s.length())
        {
            result.push_back(currSentence);
            return;
        }

        for (int j = i; j < s.length(); j++)
        {

            string tempWord = s.substr(i, j - i + 1);

            if (dict.find(tempWord) != dict.end())
            {
                string origSentence = currSentence;
                if (!currSentence.empty())
                    currSentence += " ";

                currSentence += tempWord;

                solve(j + 1, currSentence, s);

                currSentence = origSentence;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string &word : wordDict)
        {
            dict.insert(word);
        }

        string currSentence = "";
        solve(0, currSentence, s);

        return result;
    }
};
// TC-->O(2^n*n)
// SC-->O(2^n*n)

// Approach --> 2 (Using memoization)
class Solution
{
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> mp;

    vector<string> solve(string &s)
    {
        if (s.empty())
        {
            return {""};
        }

        if (mp.count(s))
            return mp[s];

        vector<string> result;
        for (int l = 1; l <= s.length(); l++)
        {
            string currWord = s.substr(0, l);
            if (dict.count(currWord))
            {
                string remainWord = s.substr(l);
                vector<string> remainResult = solve(remainWord);
                for (string &w : remainResult)
                {
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }

        return mp[s] = result;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string &word : wordDict)
        {
            dict.insert(word);
        }

        return solve(s);
    }
};
// TC-->O(2^n*n)
// SC-->O(2^n*n)
