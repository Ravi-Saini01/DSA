// 485. Max Consecutive Ones

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

class Solution
{
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0, maxones = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
                maxones = max(maxones, cnt);
            }
            else
            {
                cnt = 0;
            }
        }

        return maxones;
    }
};

//TC-->O(N)