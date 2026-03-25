83. Remove Duplicates from Sorted List

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
    class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *pre = head;
        ListNode *cur = head->next;

        while (cur != NULL)
        {
            if (pre->val == cur->val)
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                pre = pre->next;
                if (cur != NULL)
                    cur = cur->next;
            }
        }
        return head;
    }
};

//TC-->O(N)