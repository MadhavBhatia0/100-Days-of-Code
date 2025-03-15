//gfg border traversal of binary tree
void addleft(Node *root)
    {
        if(!root || root->left==NULL && root->right ==NULL) return;
        a.push_back(root->data);
        
        if(root->left!=NULL) addleft(root->left);
        else addleft(root->right);
    }
    void addleaf(Node *root)
    {
        if(!root) return;
        if(root->left!=NULL) addleaf(root->left);
        if(root->left==NULL && root->right ==NULL)
        {
            a.push_back(root->data);
            return;
        }
         addleaf(root->right);
    }
    
    vector<int> right;
    void addright(Node *root)
    {
        if(root->right==NULL && root->left==NULL) return;
        right.push_back(root->data);
        if(root->right!=NULL) addright(root->right);
        else addright(root->left);
    }
    void addrightrev(Node *root)
    {
        if(root->right!=NULL) addright(root->right);
        
        int size=right.size();
        for(int i=0;i<size;i++) a.push_back(right[size-1-i]);
    }
  public:
    vector<int> a;
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root) return a;
        
        a.push_back(root->data);
        if(root->left!=NULL)
        addleft(root->left);
        
        if(root->left!=NULL || root->right!=NULL)
        addleaf(root);
        
        addrightrev(root);
        
        return a;
    }