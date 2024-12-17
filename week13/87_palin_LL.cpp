//234. Palindrome Linked List
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
        return 0;
        if(head->next==NULL)
        return 1;

        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        ListNode* prev=NULL;
        ListNode* nex=fast->next;
        while(fast!=NULL)
        {
            nex=fast->next;
            fast->next=prev;
            prev=fast;
            fast=nex;
        }
        while(prev!=NULL)
        {
            if(prev->val!=slow->val)
            return 0;
            slow=slow->next;
            prev=prev->next;
        }return 1;
    }
};