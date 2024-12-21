//gfg Add 1 to a Linked List Number
Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* h2=rev(head);
        Node* temp=h2;
        int carry=1;
        while(carry)
        {
            (temp->data)++;
            if(temp->data==10) temp->data=0;
            else carry =0;
            if(temp->next!=NULL)
            temp=temp->next;
            else break;
        }
        if(carry)
        {
            Node* temp2=new Node(1);
            temp->next=temp2;
        }
        return rev(h2);
    }
    Node* rev(Node* head)
    {
        if(!head || !head->next) return head;
        
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL)
        {
            Node* nex=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nex;
        }
        return prev;
    }
//SC O(1)
//TC O(3N)

public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int carry=f(head);
        if(carry)
        {
            Node* temp=new Node(1);
            temp->next=head;
            head=temp;
        }
        return head;
    }
    int f(Node* head)
    {
        if(!head) return 1;
        
        int carry=f(head->next);
        head->data+=carry;
        if(head->data==10){
            head->data=0;
            return 1;
        }
        return 0;
    }
 //TC O(N)   
 //SC O(1)