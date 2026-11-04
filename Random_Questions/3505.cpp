// 3505. Minimum Operations to Make Elements Within K Subarrays Equal

// You are given an integer array nums and two integers, x and k. You can perform the following operation any number of times (including zero):

// Increase or decrease any element of nums by 1.
// Return the minimum number of operations needed to have at least k non-overlapping subarrays of size exactly x in nums, where all elements within each subarray are equal.

// Example 1:

// Input: nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2

// Output: 8

// Explanation:

// Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
// Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
// Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.
// Example 2:

// Input: nums = [9,-2,-2,-2,1,5], x = 2, k = 2

// Output: 3

// Explanation:

// Use 3 operations to subtract 3 from nums[4]. The resulting array is [9, -2, -2, -2, -2, 5].
// Now, all elements within each subarray [-2, -2] (from indices 1 to 2) and [-2, -2] (from indices 3 to 4) are equal. Since 3 operations were used, 3 is the output.

// Constraints:

// 2 <= nums.length <= 105
// -106 <= nums[i] <= 106
// 2 <= x <= nums.length
// 1 <= k <= 15
// 2 <= k * x <= nums.length

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    multiset<long long> leftSet, rightSet;
    long long sumLeft = 0, sumRight = 0;

    void add(long long val)
    {
        if (leftSet.empty() || val <= *leftSet.rbegin())
        {
            leftSet.insert(val);
            sumLeft += val;
        }
        else
        {
            rightSet.insert(val);
            sumRight += val;
        }
        balance();
    }

    void remove(long long val)
    {
        auto it = leftSet.find(val);

        if (it != leftSet.end())
        {
            sumLeft -= val;
            leftSet.erase(it);
        }
        else
        {
            it = rightSet.find(val);
            sumRight -= val;
            rightSet.erase(it);
        }
        balance();
    }

    void balance()
    {
        while (leftSet.size() > rightSet.size() + 1)
        {
            auto it = prev(leftSet.end());
            long long val = *it;

            leftSet.erase(it);
            sumLeft -= val;

            rightSet.insert(val);
            sumRight += val;
        }

        while (leftSet.size() < rightSet.size())
        {
            auto it = rightSet.begin();
            long long val = *it;

            rightSet.erase(it);
            sumRight -= val;

            leftSet.insert(val);
            sumLeft += val;
        }
    }

    long long getCost()
    {
        long long median = *leftSet.rbegin();

        return median * leftSet.size() - sumLeft + sumRight -
               median * rightSet.size();
    }

    long long minOperations(vector<int> &nums, int x, int k)
    {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        leftSet.clear();
        rightSet.clear();
        sumLeft = sumRight = 0;

        // First window
        for (int i = 0; i < x; i++)
        {
            add(nums[i]);
        }

        cost[0] = getCost();

        // Sliding window
        for (int i = x; i < n; i++)
        {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // DP
        const long long INF = 4e18;

        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                // Skip current element
                dp[j][i] = dp[j][i - 1];

                // Take subarray ending at i-1
                if (i >= x && dp[j - 1][i - x] != INF)
                {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
                }
            }
        }

        return dp[k][n];
    }
};
// TC-->O(n log x + n * k) where n is the size of the input array nums, and x is
// the size of the subarrays. The first part of the time complexity comes from calculating the cost for each subarray
// using a sliding window approach with a multiset, which takes O(log x) time for each of the n - x + 1 subarrays.
// The second part comes from the dynamic programming step, which takes O(n * k) time to fill the dp table.