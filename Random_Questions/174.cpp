// 174. Dungeon Game

// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

// Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

// To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

// Return the knight's minimum initial health so that he can rescue the princess.

// Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

// Example 1:

// Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
// Output: 7
// Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
// Example 2:

// Input: dungeon = [[0]]
// Output: 1

// Constraints:

// m == dungeon.length
// n == dungeon[i].length
// 1 <= m, n <= 200
// -1000 <= dungeon[i][j] <= 1000

// Approach-->1 (Using Recursion)
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dungeon, int m, int n)
    {
        if (i >= m || j >= n)
        {
            return INT_MAX;
        }

        if (i == m && j == n)
        {
            if (dungeon[i][j] > 0)
            {
                return 1;
            }
            return abs(dungeon[i][j]) + 1;
        }

        int right = solve(i, j + 1, dungeon, m, n);
        int down = solve(i + 1, j, dungeon, m, n);

        int result = min(right, down) - dungeon[i][j];

        return (result > 0) ? result : 1;
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        return solve(0, 0, dungeon, m, n);
    }
};
// TC-->O(2^n)-->TLE

// Approach-->2 (Using Memoization)
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dungeon, int m, int n,
              vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
        {
            return dp[i][j] = INT_MAX;
        }

        if (i == m - 1 && j == n - 1)
        {
            if (dungeon[i][j] > 0)
            {
                return dp[i][j] = 1;
            }
            return dp[i][j] = abs(dungeon[i][j]) + 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j + 1, dungeon, m, n, dp);
        int down = solve(i + 1, j, dungeon, m, n, dp);

        int result = min(right, down) - dungeon[i][j];

        return dp[i][j] = (result > 0) ? result : 1;
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, dungeon, m, n, dp);
    }
};
// TC-->O(m*n)
// SC-->O(m*n)+rss

// Aproach-->3 (Using tabulation) (Bottom up)
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    dp[i][j] = (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
                }
                else
                {
                    int right = (j + 1 >= n) ? 1e9 : dp[i][j + 1];
                    int down = (i + 1 >= m) ? 1e9 : dp[i + 1][j];

                    int result = min(right, down) - dungeon[i][j];

                    dp[i][j] = (result > 0) ? result : 1;
                }
            }
        }
        return dp[0][0];
    }
};
// TC-->O(m*n)
// Sc-->O(m*n)