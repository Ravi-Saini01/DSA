// 109. Convert Sorted List to Binary Search Tree

// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

// Example 1:

// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;

        if (!head->next)
        {
            return new TreeNode(head->val);
        }

        // find middle node of list
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *slow_pre = NULL;

        while (fast != NULL && fast->next != NULL)
        {
            slow_pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is pointing to middle node
        TreeNode *root = new TreeNode(slow->val);
        slow_pre->next = NULL;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

// TC-->O(nlogn)