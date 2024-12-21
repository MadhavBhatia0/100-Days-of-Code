// gfg Delete all occurrences of a given key in a doubly linked list
void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        if (!head_ref || !(*head_ref)) return;
        
        Node* temp=*head_ref;
        Node* head=*head_ref;
        while(temp!=NULL)
        {
            if(x==temp->data)
            {
                if(temp==head) 
                {
                    head=head->next;
                    delete temp;
                    temp=head;
                    *head_ref=temp;
                }
                else{
                    Node* nextnode=temp->next;
                    Node* prevnode=temp->prev;
                    if(nextnode) nextnode->prev=prevnode;
                    if(prevnode) prevnode->next=nextnode;
                    delete temp;
                    temp=nextnode;
                }
            }
            else temp=temp->next;
        }
    }