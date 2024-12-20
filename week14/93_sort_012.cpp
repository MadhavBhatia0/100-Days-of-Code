// gfg Sort a linked list of 0s, 1s and 2s
Node* segregate(Node* head) {
        if(!head || !head->next) return head;
        // Add code here
        Node* head0=new Node(-1);
        Node* t0=head0;
        Node* head1=new Node(-1);
        Node* t1=head1;
        Node* head2=new Node(-1);
        Node* t2=head2;
        
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==0)
            {
                t0->next=temp;
                t0=t0->next;
            }
            else if(temp->data==1)
            {
                t1->next=temp;
                t1=t1->next;
            }
            else{
                t2->next=temp;
                t2=t2->next;
            }
            temp=temp->next;
        }
        t0->next = head1->next ? head1->next : head2->next;
        t1->next=head2->next;
        t2->next = NULL;
         return head0->next;
    }