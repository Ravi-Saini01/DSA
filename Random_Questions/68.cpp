// 68. Text Justification

// Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.

// Example 1:

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified because it contains only one word.
// Example 3:

// Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]

// Constraints:

// 1 <= words.length <= 300
// 1 <= words[i].length <= 20
// words[i] consists of only English letters and symbols.
// 1 <= maxWidth <= 100
// words[i].length <= maxWidth

class Solution
{
public:
    int MAX_WIDTH;
    string getFinalWord(int i, int j, int eachWordSpace, int extraSpace,
                        vector<string> &words)
    {
        string s;

        for (int k = i; k < j; k++)
        {
            s += words[k];

            if (k == j - 1)
                continue;

            for (int space = 1; space <= eachWordSpace; space++)
                s += " ";

            if (extraSpace > 0)
            {
                s += " ";
                extraSpace--;
            }
        }

        while (s.length() < MAX_WIDTH)
        {
            s += " ";
        }

        return s;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int n = words.size();
        MAX_WIDTH = maxWidth;
        int i = 0;

        while (i < n)
        {
            int lettersCount = words[i].length();
            int j = i + 1;
            int spaceSlots = 0;

            while (j < n && spaceSlots + lettersCount + words[j].length() + 1 <=
                                maxWidth)
            {
                lettersCount += words[j].length();
                spaceSlots += 1;
                j++;
            }

            int remainingSlots = maxWidth - lettersCount;

            int eachWordSpace =
                spaceSlots == 0 ? 0 : remainingSlots / spaceSlots;
            int extraSpace = spaceSlots == 0 ? 0 : remainingSlots % spaceSlots;

            if (j == n)
            { // Means we are on last line - Left justfied
                eachWordSpace = 1;
                extraSpace = 0;
            }

            result.push_back(
                getFinalWord(i, j, eachWordSpace, extraSpace, words));
            i = j;
        }

        return result;
    }
};

// TC-->O(N*K)