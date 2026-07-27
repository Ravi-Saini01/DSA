// 407. Trapping Rain Water II

// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

// Example 1:

// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.
// Example 2:

// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10

// Constraints:

// m == heightMap.length
// n == heightMap[i].length
// 1 <= m, n <= 200
// 0 <= heightMap[i][j] <= 2 * 104

class Solution
{
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>> boundaryCells;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r)
        {
            for (int c : {0, n - 1})
            { // 0 : left most boundary, cols-1 right
              // most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        for (int c = 0; c < n; ++c)
        {
            for (int r : {0, m - 1})
            { // 0 : top most boundary, rows-1 bottom
              // most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        int trappedWater = 0;

        while (!boundaryCells.empty())
        {
            auto [height, cell] = boundaryCells.top();
            boundaryCells.pop();

            int i = cell.first;
            int j = cell.second;

            for (vector<int> &dir : directions)
            {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                    !visited[i_][j_])
                {

                    trappedWater += max(0, height - heightMap[i_][j_]);

                    boundaryCells.push(
                        {max(height, heightMap[i_][j_]), {i_, j_}});

                    visited[i_][j_] = true;
                }
            }
        }

        return trappedWater;
    }
};
// TC-->O(mnlog(mn))