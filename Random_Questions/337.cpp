// 337. House Robber III

// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

// Example 1:

// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 104

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
    vector<int> travel(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        vector<int> left_choices = travel(root->left);
        vector<int> right_choices = travel(root->right);

        vector<int> options(2);

        // option 0=value if curr node is robbed
        options[0] = root->val + left_choices[1] + right_choices[1];

        // option 1 = value if curr node is skipped
        options[1] = max(left_choices[0], left_choices[1]) +
                     max(right_choices[0], right_choices[1]);

        return options;
    }
    int rob(TreeNode *root)
    {
        vector<int> options = travel(root);

        return max(options[0], options[1]);
    }
};
// TC-->O(n)
// SC-->O(h)