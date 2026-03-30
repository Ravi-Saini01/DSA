
// Longest subarray with sum K

// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

// Examples:

// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6
// Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
// Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
// Output: 5
// Explanation: Subarrays with sum = -5 are [-5] and [-5, 8, -14, 2, 4]. The length of the longest subarray with a sum of -5 is 5.
// Input: arr[] = [10, -10, 20, 30], k = 5
// Output: 0
// Explanation: No subarray with sum = 5 is present in arr[].
// Constraints:
// 1 ≤ arr.size() ≤ 105
// -104 ≤ arr[i] ≤ 104
// -109 ≤ k ≤ 109

// Brute Force

class Solution
{
public:
    int solve(vector<int> &a)
    {
        // store best length found so far
        int maxLen = 0;
        // map prefix sum -> first index seen
        unordered_map<int, int> sumIndexMap;
        // running prefix sum
        int sum = 0;

        // iterate through the array
        for (int i = 0; i < (int)a.size(); i++)
        {
            // update running sum
            sum += a[i];

            // if sum is zero, subarray [0..i] has zero sum
            if (sum == k)
            {
                // update best length
                maxLen = i + 1;
            }
            // if this sum seen before, subarray (prevIndex..i] has zero sum
            else if (sumIndexMap.find(sum) != sumIndexMap.end())
            {
                // maximize length using previous index
                maxLen = max(maxLen, i - sumIndexMap[sum]);
            }
            // first time seeing this sum, store its index
            else
            {
                sumIndexMap[sum] = i;
            }
        }

        // return best length
        return maxLen;
    }
};

// TC-->O(N^2)

// Optimal Solution
class Solution
{
public:
    int longestSubarray(vector<int> &A, int k)
    {
        unordered_map<int, int> mpp;

        int sum = 0;
        int maxi = 0;
        int n = A.size();

        for (int i = 0; i < n; i++)
        {
            sum += A[i];

            // Case 1: subarray from 0 to i
            if (sum == k)
            {
                maxi = i + 1;
            }

            // Case 2: check if (sum - k) exists
            if (mpp.find(sum - k) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum - k]);
            }

            // Store only first occurrence of prefix sum
            if (mpp.find(sum) == mpp.end())
            {
                mpp[sum] = i;
            }
        }

        return maxi;
    }
};

// TC-->O(N)