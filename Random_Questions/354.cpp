// 354. Russian Doll Envelopes

// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Note: You cannot rotate an envelope.

// Example 1:

// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
// Example 2:

// Input: envelopes = [[1,1],[1,1],[1,1]]
// Output: 1

// Constraints:

// 1 <= envelopes.length <= 105
// envelopes[i].length == 2
// 1 <= wi, hi <= 105

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // same width -> height descending

                 return a[0] < b[0]; // width ascending
             });

        vector<int> lis;

        for (auto &e : envelopes)
        {

            int h = e[1];

            auto it = lower_bound(lis.begin(), lis.end(), h);

            if (it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }

        return lis.size();
    }
};
// TC: O(n log n)
// SC: O(n)