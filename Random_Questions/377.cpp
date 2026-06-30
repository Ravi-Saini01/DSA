// 377. Combination Sum IV

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

// Example 1:

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.
// Example 2:

// Input: nums = [9], target = 3
// Output: 0

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 1000
// All the elements of nums are unique.
// 1 <= target <= 1000

// Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

// Approach-->(Using Recursion)
class Solution
{
public:
    int solve(int target, vector<int> &nums)
    {
        if (target == 0)
            return 1;

        if (target < 0)
            return 0;

        int ans = 0;

        for (int x : nums)
        {
            ans += solve(target - x, nums);
        }

        return ans;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        return solve(target, nums);
    }
};
// TC-->O(n^T)

// Approach-->(Using Recursion + Memoization)
class Solution
{
public:
    vector<int> dp;

    int solve(int target, vector<int> &nums)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;

        if (dp[target] != -1)
            return dp[target];

        int ans = 0;

        for (int x : nums)
        {
            ans += solve(target - x, nums);
        }

        return dp[target] = ans;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        dp.assign(target + 1, -1);
        return solve(target, nums);
    }
};
// TC-->O(n*T) SC-->O(T)

// Approach-->(Using Tabulation)
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int x : nums)
            {
                if (i >= x)
                {
                    if (dp[i] > LLONG_MAX - dp[i - x])
                        dp[i] = LLONG_MAX;
                    else
                        dp[i] += dp[i - x];
                }
            }
        }

        return dp[target] > INT_MAX ? INT_MAX : (int)dp[target];
    }
};
// TC-->O(n*T) SC-->O(T)