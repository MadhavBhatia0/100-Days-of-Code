public:
    int floor(Node* root, int x) {
        // Code here
        if(!root) return -1;
        
        if(root->data==x)
        return root->data;
        
        if(root->data>x)
        return floor(root->left,x);
        
        int y=floor(root->right,x);
        return (y==-1) ? root->data : y;
    }