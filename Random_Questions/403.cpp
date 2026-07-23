// 403. Frog Jump

// A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

// Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

// If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

// Example 1:

// Input: stones = [0,1,3,5,6,8,12,17]
// Output: true
// Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
// Example 2:

// Input: stones = [0,1,2,3,4,8,9,11]
// Output: false
// Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.

// Constraints:

// 2 <= stones.length <= 2000
// 0 <= stones[i] <= 231 - 1
// stones[0] == 0
// stones is sorted in a strictly increasing order.

// Approach-->1(Recursion + Memoization)
class Solution
{
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];

    bool solve(vector<int> &stones, int curr_stone_index, int prevJump)
    {
        if (curr_stone_index == n - 1)
            return true;

        bool result = false;

        if (t[curr_stone_index][prevJump] != -1)
            return t[curr_stone_index][prevJump];

        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1;
             nextJump++)
        {

            if (nextJump > 0)
            {
                int next_stone = stones[curr_stone_index] + nextJump;

                if (mp.find(next_stone) != mp.end())
                {
                    result = result || solve(stones, mp[next_stone], nextJump);
                }
            }
        }

        return t[curr_stone_index][prevJump] = result;
    }

    bool canCross(vector<int> &stones)
    {

        if (stones[1] != 1)
            return false;

        n = stones.size();
        for (int i = 0; i < n; i++)
        {
            mp[stones[i]] = i;
        }

        memset(t, -1, sizeof(t));

        return solve(stones, 0, 0);
    }
};
// TC-->O(n^2) where n is the number of stones

// Approach-->2 (Dynamic Programming)
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();

        if (stones[1] != 1)
            return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;

        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));

        // At stone 0, previous jump = 0
        dp[0][0] = true;

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= n; k++)
            {

                if (!dp[i][k])
                    continue;

                // Try jumps: k-1, k, k+1
                for (int jump = k - 1; jump <= k + 1; jump++)
                {

                    if (jump <= 0)
                        continue;

                    int nextStone = stones[i] + jump;

                    if (mp.count(nextStone))
                    {
                        int idx = mp[nextStone];
                        dp[idx][jump] = true;
                    }
                }
            }
        }

        // If last stone is reachable with any jump
        for (int k = 0; k <= n; k++)
        {
            if (dp[n - 1][k])
                return true;
        }

        return false;
    }
};
// TC-->O(n^2) where n is the number of stones