// 453. Minimum Moves to Equal Array Elements

// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment n - 1 elements of the array by 1.

// Example 1:

// Input: nums = [1,2,3]
// Output: 3
// Explanation: Only three moves are needed (remember each move increments two elements):
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
// Example 2:

// Input: nums = [1,1,1]
// Output: 0

// Constraints:

// n == nums.length
// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// The answer is guaranteed to fit in a 32-bit integer.

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int res = 0, n = nums.size();
        int min = nums[0];

        // find min element
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < min)
            {
                min = nums[i];
            }
        }

        // add all nums[i]-min
        for (int i = 0; i < n; i++)
        {
            res += nums[i] - min;
        }
        return res;
    }
};
// TC-->O(N)