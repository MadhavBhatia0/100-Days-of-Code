vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans;
    if(!root) return ans;

    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    stack<pair<TreeNode *,int>> st;
    st.push({root,1});
    while(!st.empty())
    {
        auto it=st.top();
        TreeNode * node=it.first;
        int num=it.second;
        if(num==1)
        {
            preorder.push_back(node->data);
            st.top().second++;
            if(node->left!=NULL) st.push({node->left,1});
        }
        else if(num==2)
        {
            inorder.push_back(node->data);
            st.top().second++;
            if(node->right!=NULL) st.push({node->right,1});
        }
        else if(num==3)
        {
            postorder.push_back(node->data);
            st.pop();
        }
    }
    
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}
//TC-O(N)
//SC-O(3N+N)