// 169. Majority Element

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109
// The input is generated such that a majority element will exist in the array.

// Follow-up: Could you solve the problem in linear time and in O(1) space?

// Brute Force
class Solution
{
public:
    // Function to find the majority element in an array
    int majorityElement(vector<int> &nums)
    {

        // Size of the given array
        int n = nums.size();

        // Iterate through each element of the array
        for (int i = 0; i < n; i++)
        {

            // Counter to count occurrences of nums[i]
            int cnt = 0;

            // Count the frequency of nums[i] in the array
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == nums[i])
                {
                    cnt++;
                }
            }

            // Check if frequency of nums[i] is greater than n/2
            if (cnt > (n / 2))
            {
                // Return the majority element
                return nums[i];
            }
        }

        // Return -1 if no majority element is found
        return -1;
    }
};
// TC-->O(N^2)
// SC-->O(1)

// Better Solution (Using map)
class Solution
{
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        // find the frequency of each element

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        // iterate in the map and find majority element
        for (auto &it : mp)
        {
            if (it.second > (n / 2))
            {
                return it.second;
            }
        }
        return -1;
    }
};

// TC-->O(N)
// SC-->O(N)

// Optimal Solution (Moore's voting algo)
class Solution
{
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int ele, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                ele = nums[i];
            }
            else if (nums[i] == ele)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return ele;
    }
};
// TC-->O(N)
// SC-->O(1)
