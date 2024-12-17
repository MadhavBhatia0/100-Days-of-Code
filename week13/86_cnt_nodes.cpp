//gfg Find length of Loop

int countNodesinLoop(Node *head) {
        // Code here
        if(!head) return 0;
        int count=1;
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
        {

            fast=fast->next;
            while(fast!=slow)
            {
                count++;
                fast=fast->next;
            }
            return count;
        }
        }
        
        return 0;
    }