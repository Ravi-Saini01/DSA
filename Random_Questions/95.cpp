// 95. Unique Binary Search Trees II

// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

// Example 1:

// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 8

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
    vector<TreeNode *> solve(int start, int end,
                             map<pair<int, int>, vector<TreeNode *>> &mp)
    {

        if (start > end)
        {
            return {NULL};
        }

        if (start == end)
        {
            TreeNode *root = new TreeNode(start);
            return {root};
        }

        if (mp.find({start, end}) != mp.end())
            return mp[{start, end}];

        vector<TreeNode *> result;
        for (int i = start; i <= end; i++)
        {

            vector<TreeNode *> leftList = solve(start, i - 1, mp);
            vector<TreeNode *> rightList = solve(i + 1, end, mp);

            for (TreeNode *leftRoot : leftList)
            {

                for (TreeNode *rightRoot : rightList)
                {

                    TreeNode *root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;

                    result.push_back(root);
                }
            }
        }

        return mp[{start, end}] = result;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        map<pair<int, int>, vector<TreeNode *>> mp;

        return solve(1, n, mp);
    }
};