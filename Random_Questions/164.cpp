// 164. Maximum Gap

// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra space.

// Example 1:

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
// Example 2:

// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109

// (Using sorting)
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        sort(nums.begin(), nums.end());
        int maxgap = nums[1] - nums[0];

        for (int i = 2; i < n; i++)
        {
            maxgap = max(maxgap, nums[i] - nums[i - 1]);
        }
        return maxgap;
    }
};
// TC-->O(nlogn)

// Approach--> (Using non comprison sorting)
class Solution
{
public:
    int getMax(vector<int> &arr)
    {
        int maxVal = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }
        return maxVal;
    }

    void countingSort(vector<int> &arr, long long exp)
    {
        int n = arr.size();
        vector<int> output(n);
        int count[10] = {0};

        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
    }

    void radixSort(vector<int> &arr)
    {
        int maxVal = getMax(arr);

        // FIX: use long long
        for (long long exp = 1; maxVal / exp > 0; exp *= 10)
        {
            countingSort(arr, exp);
        }
    }

    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        radixSort(nums);

        int maxgap = nums[1] - nums[0];
        for (int i = 2; i < n; i++)
        {
            maxgap = max(maxgap, nums[i] - nums[i - 1]);
        }
        return maxgap;
    }
};
// TC-->O(N)