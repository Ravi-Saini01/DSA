// 480. Sliding Window Median

// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

// For examples, if arr = [2,3,4], the median is 3.
// For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
// You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
// Explanation:
// Window position                Median
// ---------------                -----
// [1  3  -1] -3  5  3  6  7        1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7        3
//  1  3  -1  -3 [5  3  6] 7        5
//  1  3  -1  -3  5 [3  6  7]       6
// Example 2:

// Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
// Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]

// Constraints:

// 1 <= k <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> ans;

        multiset<long long> left, right;

        // Balance the two sets
        auto balance = [&]()
        {
            // left should have equal or one more element than right
            while (left.size() > right.size() + 1)
            {
                auto it = prev(left.end());
                right.insert(*it);
                left.erase(it);
            }

            while (left.size() < right.size())
            {
                auto it = right.begin();
                left.insert(*it);
                right.erase(it);
            }
        };

        // Add an element
        auto add = [&](long long x)
        {
            if (left.empty() || x <= *prev(left.end()))
                left.insert(x);
            else
                right.insert(x);

            balance();
        };

        // Remove an element
        auto remove = [&](long long x)
        {
            auto it = left.find(x);

            if (it != left.end())
            {
                left.erase(it);
            }
            else
            {
                it = right.find(x);
                right.erase(it);
            }

            balance();
        };

        // First window
        for (int i = 0; i < k; i++)
        {
            add(nums[i]);
        }

        // Get median
        auto getMedian = [&]() -> double
        {
            if (k % 2 == 1)
            {
                return (double)*prev(left.end());
            }
            else
            {
                long long a = *prev(left.end());
                long long b = *right.begin();

                return ((double)a + (double)b) / 2.0;
            }
        };

        ans.push_back(getMedian());

        // Slide window
        for (int i = k; i < nums.size(); i++)
        {
            remove(nums[i - k]);
            add(nums[i]);

            ans.push_back(getMedian());
        }

        return ans;
    }
};
// TC-->O(n log k)