// 373. Find K Pairs with Smallest Sums

// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

// Define a pair (u, v) which consists of one element from the first array and one element from the second array.

// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// Example 2:

// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

// Constraints:

// 1 <= nums1.length, nums2.length <= 105
// -109 <= nums1[i], nums2[i] <= 109
// nums1 and nums2 both are sorted in non-decreasing order.
// 1 <= k <= 104
// k <= nums1.length * nums2.length

class Solution
{
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                       int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<P, vector<P>, greater<P>> pq; // min-heap

        set<pair<int, int>> visited;
        visited.insert({0, 0});

        int sum = nums1[0] + nums2[0];

        pq.push({sum, {0, 0}});

        vector<vector<int>> result;
        while (k-- && !pq.empty())
        {

            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});

            // Push (i, j+1) if possible
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }

            // Push (i+1, j) if possible
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end())
            {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
        }

        return result;
    }
};
// TC-->O(klogk)  SC-->O(k)