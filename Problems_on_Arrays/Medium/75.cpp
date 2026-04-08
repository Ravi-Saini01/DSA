// 75. Sort Colors

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

// Brute Force Approach
/*
   use merge sort
   TC-->O(nlogn)
*/

// Approach-->2 (Using 3 count variables)
class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                cnt0++;
            }
            else if (arr[i] == 1)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }

        for (int i = 0; i < cnt0; i++)
        {
            arr[i] = 0;
        }

        for (int i = cnt0; i < cnt0 + cnt1; i++)
        {
            arr[i] = 1;
        }

        for (int i = cnt0 + cnt1; i < n; i++)
        {
            arr[i] = 2;
        }
    }
};
// TC-->O(2N)
// SC-->O(1)

// Approach-->3 (Using Dutch National Flag Algorithm)
class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
// TC-->O(N)
// Sc-->O(1)