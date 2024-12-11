//gfg Count Linked List Nodes
public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        int c=0;
        while(head!=NULL)
        {
            head=head->next;
            c++;
        }
        return c;
    }

//gfg Search in Linked List
public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        while(head!=NULL)
        {
            if(head->data==key) return 1;
            head=head->next;
        }
        return 0;
    }

//Array to Linked List
int n=arr.size();
        if(n==0) return NULL;
        
        Node* head;
        Node *temp2;
        for(int i=0;i<n;i++)
        {
            Node* temp=new Node(arr[i]);
            if(i==0) 
            {
                head=temp;
                temp2=temp;
            }
            else{
                temp2->next=temp;
                temp2=temp;
            }
        }
        return head;

//gfg Linked List Insertion At En
public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head==NULL)
        {
            Node *temp2=new Node(x);
            return temp2;
        }
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        Node *temp2=new Node(x);
        temp->next=temp2;
        return head;
    }