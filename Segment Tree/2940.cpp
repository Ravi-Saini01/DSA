// 2940. Find Building Where Alice and Bob Can Meet

// You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

// If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

// You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.

// Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

// Example 1:

// Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
// Output: [2,5,-1,5,2]
// Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2].
// In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5].
// In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
// In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
// In the fifth query, Alice and Bob are already in the same building.
// For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
// For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
// Example 2:

// Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
// Output: [7,6,-1,4,6]
// Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
// In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
// In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
// In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
// In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
// For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
// For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

// Constraints:

// 1 <= heights.length <= 5 * 104
// 1 <= heights[i] <= 109
// 1 <= queries.length <= 5 * 104
// queries[i] = [ai, bi]
// 0 <= ai, bi <= heights.length - 1

class Solution
{
public:
    // Builds the segment tree using the max function and stores indices
    void buildSegmentTree(int i, int l, int r, int segmentTree[],
                          vector<int> &heights)
    {
        if (l == r)
        {
            segmentTree[i] = l; // Store the index
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, heights);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, heights);

        // Store the index of the maximum element
        segmentTree[i] =
            (heights[segmentTree[2 * i + 1]] >= heights[segmentTree[2 * i + 2]])
                ? segmentTree[2 * i + 1]
                : segmentTree[2 * i + 2];
    }

    // Function to construct the segment tree
    int *constructST(vector<int> &heights, int n)
    {
        int *segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, heights);
        return segmentTree;
    }

    // Function to query the segment tree for the index of the maximum value in
    // range [start, end]
    int querySegmentTree(int start, int end, int i, int l, int r,
                         int segmentTree[], vector<int> &heights)
    {
        if (l > end || r < start)
        {
            return -1; // Return -1 for out-of-bound queries
        }

        if (l >= start && r <= end)
        {
            return segmentTree[i]; // Return the index of the maximum element
        }

        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid,
                                         segmentTree, heights);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r,
                                          segmentTree, heights);

        // Handle cases where one side is out of bounds
        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        // Return the index of the maximum element
        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex
                                                           : rightIndex;
    }

    // Function to return the index of the maximum element in the range from a
    // to b
    int RMIQ(int st[], vector<int> &heights, int n, int a, int b)
    {
        return querySegmentTree(a, b, 0, 0, n - 1, st, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int> &heights,
                                        vector<vector<int>> &queries)
    {
        int n = heights.size();
        int *segmentTree = constructST(heights, n);

        vector<int> result;
        for (auto &query : queries)
        {
            int alice = min(query[0], query[1]);
            int bob = max(query[0], query[1]);

            if (alice == bob || heights[bob] > heights[alice])
            {
                result.push_back(bob);
                continue;
            }

            int l = bob + 1;
            int r = n - 1;
            int result_idx = INT_MAX;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                int idx = RMIQ(segmentTree, heights, n, l, mid);

                if (heights[idx] > max(heights[alice], heights[bob]))
                {
                    r = mid - 1;
                    result_idx = min(result_idx, idx);
                }
                else
                {
                    l = mid + 1;
                }
            }

            if (result_idx == INT_MAX)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(result_idx);
            }
        }
        return result;
    }
};

// TC-->O(qlog^2n)