//116. Populating Next Right Pointers in Each Node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        Node* connect(Node* root) {
            if(!root) return root;
    
            queue<Node*> q;
            q.push(root);
            int count=0,level=0;
            while(!q.empty())
            {
                Node* f=q.front();
                q.pop();
                count++;
                if(count==(1<<level) )
                {
                    f->next=NULL;
                    count=0;
                    level++;
                }
                else 
                {
                    f->next=q.front();
                }
    
                if(f->left!=NULL) q.push(f->left);
                if(f->right!=NULL) q.push(f->right);
            }
            return root;
        }
    };