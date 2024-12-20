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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* head2=head->next;
        ListNode* t1=head;
        ListNode* t2=head->next;
        while(t2)
        {
            t1->next=t2->next;
            if(t1->next==NULL) break;
            t1=t1->next;
            t2->next=t1->next;
            t2=t2->next;
        }
        t1->next=head2;
        return head;
    }
};
//SC o(1)
//TC o(N)