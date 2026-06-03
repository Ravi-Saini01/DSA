// 324. Wiggle Sort II

// Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

// You may assume the input array always has a valid answer.

// Example 1:

// Input: nums = [1,5,1,1,6,4]
// Output: [1,6,1,5,1,4]
// Explanation: [1,4,1,5,1,6] is also accepted.
// Example 2:

// Input: nums = [1,3,2,2,3,1]
// Output: [2,3,1,3,1,2]

// Constraints:

// 1 <= nums.length <= 5 * 104
// 0 <= nums[i] <= 5000
// It is guaranteed that there will be an answer for the given input nums.

// Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?

// Approach -->1 (Using sorting and extra space)
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        sort(nums.begin(), nums.end());
        int i = 1, j = n - 1;

        while (i < n)
        {
            ans[i] = nums[j];
            i += 2;
            j--;
        }
        i = 0;

        while (i < n)
        {
            ans[i] = nums[j];
            i += 2;
            j--;
        }

        for (int k = 0; k < n; k++)
        {
            nums[k] = ans[k];
        }
    }
};
// TC--> O(nlogn) due to sorting
// SC--> O(n) due to extra space used for ans vector
