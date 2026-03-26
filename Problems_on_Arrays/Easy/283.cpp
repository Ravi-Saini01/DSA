// 283. Move Zeroes

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

class Solution
{
    void moveZeroes(vector<int> &arr)
    {
        int n = arr.size();

        if (n < 2)
            return;

        int j = -1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                j = i;
                break;
            }
        }
        if (j == -1)
            return;

        for (int i = j + 1; i < n; i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};

// TC-->O(N)
