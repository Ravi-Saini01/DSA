// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.

// Example 1:

// Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
// "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
// Example 2:

// Input: words = ["cat","dog","catdog"]
// Output: ["catdog"]

// Constraints:

// 1 <= words.length <= 104
// 1 <= words[i].length <= 30
// words[i] consists of only lowercase English letters.
// All the strings of words are unique.
// 1 <= sum(words[i].length) <= 105

class Solution
{
public:
    int n;
    unordered_map<string, bool> mp;

    bool isConcat(string word, unordered_set<string> &st)
    {
        if (mp.find(word) != mp.end())
        {
            return mp[word];
        }

        int l = word.length();

        for (int i = 0; i < l; i++)
        {
            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);

            if (st.find(prefix) != st.end() && isConcat(suffix, st) ||
                st.find(prefix) != st.end() && st.find(suffix) != st.end())
                return mp[word] = true;
        }
        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        n = words.size();
        mp.clear();
        vector<string> result;
        unordered_set<string> st(words.begin(), words.end());

        for (int i = 0; i < n; i++)
        {
            if (isConcat(words[i], st))
                result.push_back(words[i]);
        }
        return result;
    }
};
// TC-->O(n * l^2) where n is the number of words and l is the average length of the words.