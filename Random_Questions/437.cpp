// 437. Path Sum III

// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

// Example 1:

// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.
// Example 2:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: 3

// Constraints:

// The number of nodes in the tree is in the range [0, 1000].
// -109 <= Node.val <= 109
// -1000 <= targetSum <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int total = 0;
    void findpathsum(TreeNode *curr, long long sum, int tar,
                     unordered_map<long long, int> &hm)
    {
        if (curr == NULL)
            return;

        sum += curr->val;

        if (hm.find(sum - tar) != hm.end())
        {
            total += hm[sum - tar];
        }

        hm[sum]++;

        findpathsum(curr->left, sum, tar, hm);
        findpathsum(curr->right, sum, tar, hm);

        hm[sum]--;
    }
    int pathSum(TreeNode *root, int Sum)
    {
        total = 0;

        if (root == NULL)
            return 0;

        unordered_map<long long, int> hm;
        hm[0] = 1;

        findpathsum(root, 0, Sum, hm);

        return total;
    }
};
// TC---> O(n) where n is the number of nodes in the tree. We traverse each node once.