Longest subarray with given sum K(positives)

    // Brute force

    class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLength = 0;

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {
                /* add all the elements of
                   subarray = nums[startIndex...endIndex]  */
                int currentSum = 0;
                for (int i = startIndex; i <= endIndex; i++)
                {
                    currentSum += nums[i];
                }

                if (currentSum == k)
                    maxLength = max(maxLength, endIndex - startIndex + 1);
            }
        }
        return maxLength;
    }
};

// TC-->O(O^3)

// Optimak solution

class Solution
{
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxlen = 0;
        int sum = nums[0];
        int left = 0, right = 0;

        while (right < n)
        {
            while (left <= right && sum > k)
            {
                sum -= nums[left];
                left++;
            }

            if (sum == k)
            {
                maxlen = max(maxlen, right - left + 1);
            }

            right++;
            if (right < n)
            {
                sum += nums[right];
            }
        }
        return maxlen;
    }
};

// TC-->O(N)