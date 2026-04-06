// 128. Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Example 3:

// Input: nums = [1,0,1,2]
// Output: 3

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

// Brute Force

class Solution
{
private:
    // Helper function to perform linear search
    bool linearSearch(vector<int> &a, int num)
    {
        int n = a.size();
        // Traverse through the array
        for (int i = 0; i < n; i++)
        {
            if (a[i] == num)
                return true;
        }
        return false;
    }

public:
    // Function to find the longest consecutive sequence
    int longestConsecutive(vector<int> &nums)
    {
        // If the array is empty
        if (nums.size() == 0)
        {
            return 0;
        }
        int n = nums.size();
        // Initialize the longest sequence length
        int longest = 1;

        // Iterate through each element in the array
        for (int i = 0; i < n; i++)
        {
            // Current element
            int x = nums[i];
            // Count of the current sequence
            int cnt = 1;

            // Search for consecutive numbers
            while (linearSearch(nums, x + 1) == true)
            {
                // Move to the next number in the sequence
                x += 1;
                // Increment the count of the sequence
                cnt += 1;
            }

            // Update the longest sequence length found so far
            longest = max(longest, cnt);
        }
        return longest;
    }
};
// TC-->O(N^2)

// Better Approach

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int lastsmaller = INT_MIN;
        int cnt = 0;
        int longest = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] - 1 == lastsmaller)
            {
                cnt++;
                lastsmaller = nums[i];
            }
            else if (nums[i] != lastsmaller)
            {
                cnt = 1;
                lastsmaller = nums[i];
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};
// TC-->O(nlogn)

// Optimal Approach

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        int longest = 1;
        unordered_set<int> st;

        // put all array element into set
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        // traverse the set to find the longest
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int cnt = 1;
                int x = it; // starting element of sequence

                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

// TC-->O(N)
// SC-->O(N)