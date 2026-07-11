// 391. Perfect Rectangle

// Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

// Return true if all the rectangles together form an exact cover of a rectangular region.

// Example 1:

// Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
// Output: true
// Explanation: All 5 rectangles together form an exact cover of a rectangular region.
// Example 2:

// Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
// Output: false
// Explanation: Because there is a gap between the two rectangular regions.
// Example 3:

// Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
// Output: false
// Explanation: Because two of the rectangles overlap with each other.

// Constraints:

// 1 <= rectangles.length <= 2 * 104
// rectangles[i].length == 4
// -105 <= xi < ai <= 105
// -105 <= yi < bi <= 105

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        long long area = 0;

        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        set<pair<int, int>> corners;

        for (auto &r : rectangles)
        {
            int x1 = r[0], y1 = r[1];
            int x2 = r[2], y2 = r[3];

            // Total area
            area += 1LL * (x2 - x1) * (y2 - y1);

            // Bounding rectangle
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            // Four corners of current rectangle
            vector<pair<int, int>> pts = {
                {x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};

            // Toggle corners
            for (auto &p : pts)
            {
                if (corners.count(p))
                    corners.erase(p);
                else
                    corners.insert(p);
            }
        }

        // Area must match
        long long expectedArea = 1LL * (maxX - minX) * (maxY - minY);
        if (area != expectedArea)
            return false;

        // Exactly four corners should remain
        if (corners.size() != 4)
            return false;

        // They must be the bounding rectangle corners
        if (!corners.count({minX, minY}) || !corners.count({minX, maxY}) ||
            !corners.count({maxX, minY}) || !corners.count({maxX, maxY}))
            return false;

        return true;
    }
};
// TC-->O(nlog(n))
// SC-->O(n)