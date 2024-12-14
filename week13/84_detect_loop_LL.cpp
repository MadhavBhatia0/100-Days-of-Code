//141. Linked List Cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
        return 0;
        if(head->next==head)
        return 1;

        ListNode *fast=head->next;
        ListNode *slow=head;
        while((fast!=NULL&&fast->next!=NULL)&&fast!=slow)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return (fast==slow);
    }
};
//TC O(N)
//SC O(1)