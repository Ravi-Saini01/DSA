// 352. Data Stream as Disjoint Intervals

// Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

// Implement the SummaryRanges class:

// SummaryRanges() Initializes the object with an empty stream.
// void addNum(int value) Adds the integer value to the stream.
// int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.

// Example 1:

// Input
// ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
// [[], [1], [], [3], [], [7], [], [2], [], [6], []]
// Output
// [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

// Explanation
// SummaryRanges summaryRanges = new SummaryRanges();
// summaryRanges.addNum(1);      // arr = [1]
// summaryRanges.getIntervals(); // return [[1, 1]]
// summaryRanges.addNum(3);      // arr = [1, 3]
// summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
// summaryRanges.addNum(7);      // arr = [1, 3, 7]
// summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
// summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
// summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
// summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
// summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]

// Constraints:

// 0 <= value <= 104
// At most 3 * 104 calls will be made to addNum and getIntervals.
// At most 102 calls will be made to getIntervals.

// Follow up: What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?

// Approach-3 - (Using ordered map) - O(logn)
class SummaryRanges
{
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value)
    {
        int left = value;
        int right = value;
        auto just_greater = intervals.upper_bound(value);

        if (just_greater != intervals.begin())
        {

            auto ek_peeche = just_greater;
            --ek_peeche;

            if (ek_peeche->second >= value)
            {
                return;
            }
            if (ek_peeche->second == value - 1)
            {
                left = ek_peeche->first;
            }
        }
        if (just_greater != intervals.end() &&
            just_greater->first == value + 1)
        {
            right = just_greater->second;
            intervals.erase(just_greater);
        }
        intervals[left] = right;
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> result;

        for (const auto &p : intervals)
        {
            result.push_back({p.first, p.second});
        }

        return result;
    }
};
// TC-->O(logn) for addNum() and O(n) for getIntervals()