// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

// (Approach --> 1)(using sorting)

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();

    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < n; i++)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());

        mp[temp].push_back(strs[i]);
    }

    for (auto it : mp)
    {
        result.push_back(it.second);
    }

    return result;
}

// TC--> O(n*klogk);

// (Approach --> 2)(without using sorting)

class Solution
{
public:
    string generate(string &s)
    {
        int count[26] = {0};

        for (char &ch : s)
        {
            count[ch - 'a']++;
        }
        string new_s;

        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                new_s += string(count[i], i + 'a');
            }
        }
        return new_s;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (string &s : strs)
        {
            string new_s = generate(s);
            mp[new_s].push_back(s);
        }
        vector<vector<string>> result;

        for (auto &it : mp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};

//TC-->O(N*K)
//SC-->O(N*K)
