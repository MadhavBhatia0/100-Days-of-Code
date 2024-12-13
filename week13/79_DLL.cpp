//gfg Introduction to Doubly Linked List
public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(!n) return NULL;
        
        Node* head=new Node(arr[0]);
        Node* temp=head;
        for(int i=1;i<n;i++)
        {
            Node* temp2=new Node(arr[i]);
            temp->next=temp2;
            temp2->prev=temp;
            temp=temp2;
        }
        return head;
    }

//gfg Doubly linked list Insertion at given position
    public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int p, int data) {
        // code here
        Node *temp=head;
        while(p)
        {
            if(temp!=NULL) temp=temp->next;
            p--;
        }
        Node* n=new Node(data);
        if(temp!=NULL)
        {
            n->prev=temp;
            if(temp->next!=NULL)
            {
            Node* temp2=temp->next;
            temp2->prev=n;
            n->next=temp2;
            }
            temp->next=n;
        }
        return head;
    }
//gfg Delete in a Doubly Linked List
public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(!head) return NULL;
        if(x==1) 
        {
            head=head->next;
            head->prev=NULL;
            return head;
        }
        Node*temp=head;
        while(x-1)
        {
            temp=temp->next;
            x--;
        }
        Node *tempp=temp->prev;
        tempp->next=temp->next;
        if(temp->next!=NULL)
        {
            tempp->next->prev=tempp;
        }
        
        
        return head;
    }
// gfg Reverse a Doubly Linked List
public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(!head || !head->next) return head;
        
        DLLNode* pr=NULL;
        DLLNode* temp=head;
        while(temp!=NULL)
        {
            DLLNode* nx=temp->next;
            temp->next=pr;
            if(pr!=NULL)
            pr->prev=temp;
            pr=temp;
            temp=nx;
        }
        return pr;
    }