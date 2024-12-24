// gfg Remove duplicates from a sorted doubly linked list
Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if(!head || !head->next) return head;
        
        Node* temp=head;
        while(temp->next!=NULL)
        {
            if(temp->next->data==temp->data)
            {
                Node* nexnode=temp->next->next;
                temp->next=nexnode;
                if(nexnode!=NULL) nexnode->prev=temp;
            }
            else temp=temp->next;
        }
        return head;
    }
//TC O(N)
//SC O(1)