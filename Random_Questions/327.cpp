// 327. Count of Range S

// Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

// Example 1:

// Input: nums = [-2,5,-1], lower = -2, upper = 2
// Output: 3
// Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
// Example 2:

// Input: nums = [0], lower = 0, upper = 0
// Output: 1

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// -105 <= lower <= upper <= 105
// The answer is guaranteed to fit in a 32-bit integer.

class Solution
{
public:
    long long mergeSort(vector<long long> &prefix, int left, int right,
                        int lower, int upper)
    {
        if (right - left <= 1)
            return 0;

        int mid = left + (right - left) / 2;
        long long count = 0;

        count += mergeSort(prefix, left, mid, lower, upper);
        count += mergeSort(prefix, mid, right, lower, upper);

        int low = mid, high = mid;

        for (int i = left; i < mid; i++)
        {
            while (low < right && prefix[low] - prefix[i] < lower)
                low++;

            while (high < right && prefix[high] - prefix[i] <= upper)
                high++;

            count += (high - low);
        }

        // Merge step
        vector<long long> temp;
        int i = left, j = mid;

        while (i < mid && j < right)
        {
            if (prefix[i] <= prefix[j])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[j++]);
        }

        while (i < mid)
            temp.push_back(prefix[i++]);
        while (j < right)
            temp.push_back(prefix[j++]);

        for (int k = 0; k < temp.size(); k++)
        {
            prefix[left + k] = temp[k];
        }

        return count;
    }
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return (int)mergeSort(prefix, 0, n + 1, lower, upper);
    }
};
// TC-->O(n log n) SC-->O(n)