int findCeil(Node* root, int input) {
    if (!root) return -1;
    
    if(root->data==input)
    return root->data;
    
    if(root->data<input)
    return findCeil(root->right,input);
    
    int x=findCeil(root->left,input);
    return (x==-1)? root->data : x;
}