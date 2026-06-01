// 321. Create Maximum Number

// You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

// Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

// Return an array of the k digits representing the answer.

// Example 1:

// Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
// Output: [9,8,6,5,3]
// Example 2:

// Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
// Output: [6,7,6,0,4]
// Example 3:

// Input: nums1 = [3,9], nums2 = [8,9], k = 3
// Output: [9,8,9]

// Constraints:

// m == nums1.length
// n == nums2.length
// 1 <= m, n <= 500
// 0 <= nums1[i], nums2[i] <= 9
// 1 <= k <= m + n
// nums1 and nums2 do not have leading zeros.

class Solution
{
public:
    // monotonic stack
    vector<int> solve(int k, vector<int> &nums)
    {
        int n = nums.size();
        if (k > n)
            return {};

        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            while (!ans.empty() && nums[i] > ans.back() &&
                   ans.size() - 1 + n - i >= k)
            {
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        }
        while (ans.size() > k)
        {
            ans.pop_back();
        }
        return ans;
    }

    void merge(vector<int> &ans, vector<int> &v1, vector<int> &v2)
    {
        int m = v1.size();
        int n = v2.size();

        int i = 0;
        int j = 0;

        while (i < m && j < n)
        {
            if (v1[i] == v2[j])
            {
                int tempi = i;
                int tempj = j;

                while (tempi < m && tempj < n && v1[tempi] == v2[tempj])
                {
                    tempi++;
                    tempj++;
                }
                if (tempj == n)
                {
                    ans.push_back(v1[i]);
                    i++;
                }
                else if (tempi == m)
                {
                    ans.push_back(v2[j]);
                    j++;
                }
                else if (v1[tempi] > v2[tempj])
                {
                    ans.push_back(v1[i]);
                    i++;
                }
                else
                {
                    ans.push_back(v2[j]);
                    j++;
                }
                continue;
            }
            if (v1[i] > v2[j])
            {
                ans.push_back(v1[i]);
                i++;
            }
            else
            {
                ans.push_back(v2[j]);
                j++;
            }
        }

        while (i < m)
        {
            ans.push_back(v1[i]);
            i++;
        }
        while (j < n)
        {
            ans.push_back(v2[j]);
            j++;
        }
    }
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> ans;
        for (int i = 0; i <= k; i++)
        {
            vector<int> temp1 = solve(i, nums1);
            vector<int> temp2 = solve(k - i, nums2);
            vector<int> temp;

            merge(temp, temp1, temp2);

            if (temp.size() == k)
            {
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
// TC--> O(k * (m + n)^2)
//  SC--> O(k) for the answer vector, O(m + n) for the temporary vectors used in the merge function.