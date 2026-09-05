// 466. Count The Repetitions

// We define str = [s, n] as the string str which consists of the string s concatenated n times.

// For example, str == ["abc", 3] =="abcabcabc".
// We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.

// For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
// You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].

// Return the maximum integer m such that str = [str2, m] can be obtained from str1.

// Example 1:

// Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
// Output: 2
// Example 2:

// Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
// Output: 1

// Constraints:

// 1 <= s1.length, s2.length <= 100
// s1 and s2 consist of lowercase English letters.
// 1 <= n1, n2 <= 106

class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        // ptr2--> s2+s2+s2......  str2
        // ptr1--> s1+s1+..s1 --> str1

        int len1 = s1.length();
        int len2 = s2.length();

        unordered_map<int, int> increase;

        for (int i = 0; i < len2; i++)
        {
            int ptr1 = 0;
            int ptr2 = i;
            while (ptr1 != len1)
            {
                if (s1[ptr1] == s2[ptr2 % len2])
                {
                    ptr1++;
                    ptr2++;
                }
                else
                {
                    ptr1++;
                }
            }
            increase[i] = ptr2 - i;
        }

        // O(len2*len1)

        int ptr = 0;
        int totalMatchedLength = 0;

        for (int i = 0; i < n1; i++)
        {
            totalMatchedLength += increase[ptr];
            ptr += increase[ptr];
            ptr %= len2;
        }

        // O(n1+len2*len1)

        return totalMatchedLength / (len2 * n2);
    }
};
// TC-->O(n1+len2*len1)