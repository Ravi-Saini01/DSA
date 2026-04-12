// 168. Excel Sheet Column Title

// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28
// ...

// Example 1:

// Input: columnNumber = 1
// Output: "A"
// Example 2:

// Input: columnNumber = 28
// Output: "AB"
// Example 3:

// Input: columnNumber = 701
// Output: "ZY"

// Constraints:

// 1 <= columnNumber <= 231 - 1

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string result;

        while (columnNumber)
        {
            columnNumber--;

            int remain = columnNumber % 26;
            char ch = remain + 'A';
            result.push_back(ch);

            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
// TC-->O(logn)