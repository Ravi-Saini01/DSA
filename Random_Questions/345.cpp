// 345. Reverse Vowels of a String

// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// Example 1:

// Input: s = "IceCreAm"

// Output: "AceCreIm"

// Explanation:

// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

// Example 2:

// Input: s = "leetcode"

// Output: "leotcede"

// Constraints:

// 1 <= s.length <= 3 * 105
// s consist of printable ASCII characters.

class Solution
{
public:
    bool isVowel(char c)
    {
        c = toLower(c);

        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s)
    {
        int i = 0, j - s.length() - 1;

        while (i < j)
        {
            while (i < j && !isVowel(s[i]))
            {
                i++;
            }

            while (i < j && !isVowel(s[j]))
            {
                j--;
            }

            if (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
// TC-->O(N)