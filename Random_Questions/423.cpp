// 423. Reconstruct Original Digits from English

// Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.

// Example 1:

// Input: s = "owoztneoer"
// Output: "012"
// Example 2:

// Input: s = "fviefuro"
// Output: "45"

// Constraints:

// 1 <= s.length <= 105
// s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
// s is guaranteed to be valid.

class Solution
{
public:
    string originalDigits(string s)
    {
        vector<int> count(26, 0);

        // Count frequency of each character
        for (char c : s)
        {
            count[c - 'a']++;
        }

        vector<int> num(10, 0);

        // Unique cases
        num[0] = count['z' - 'a']; // zero
        num[2] = count['w' - 'a']; // two
        num[4] = count['u' - 'a']; // four
        num[6] = count['x' - 'a']; // six
        num[8] = count['g' - 'a']; // eight

        // Derived cases
        num[1] = count['o' - 'a'] - num[0] - num[2] - num[4]; // one
        num[3] = count['h' - 'a'] - num[8];                   // three
        num[5] = count['f' - 'a'] - num[4];                   // five
        num[7] = count['s' - 'a'] - num[6];                   // seven
        num[9] = count['i' - 'a'] - num[5] - num[6] - num[8]; // nine

        string ans;

        for (int i = 0; i < 10; i++)
        {
            while (num[i]-- > 0)
            {
                ans += char('0' + i);
            }
        }

        return ans;
    }
};
// TC-->O(N)