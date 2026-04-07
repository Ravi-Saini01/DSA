// 143. Reorder List

// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

// Constraints:

// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000

// Approach-1 (Using stack)
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        stack<ListNode *> st;

        ListNode *curr = head;
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
        }

        int k = st.size() / 2;
        curr = head;
        while (k--)
        {
            ListNode *topNode = st.top();
            st.pop();

            ListNode *temp = curr->next;
            curr->next = topNode;
            topNode->next = temp;
            curr = temp;
        }

        curr->next = NULL;
    }
};

class Solution
{
public:
    ListNode *curr;

    void solve(ListNode *head)
    {
        if (head == NULL)
            return;

        solve(head->next);

        if (curr == NULL)
            return;

        ListNode *temp = curr->next;

        if (head == curr || curr->next == head)
        {
            head->next = NULL;
            curr = NULL; // stop further processing
            return;
        }

        curr->next = head;
        head->next = temp;

        curr = temp;
    }

    void reorderList(ListNode *head)
    {
        curr = head;
        solve(head);
    }
};
// TC-->O(N)
// SC-->O(N)

// Approach-->3 (Using iterative approach)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // Step 1: Find middle
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode *second = slow->next;
        slow->next = NULL;

        ListNode *prev = NULL;
        while (second)
        {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // Step 3: Merge two halves
        ListNode *first = head;
        second = prev;

        while (second)
        {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
// TC-->O(N)
// SC-->O(1)