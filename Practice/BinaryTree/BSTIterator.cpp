/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    private:
    stack<TreeNode*> st;
    public:
        BSTIterator(TreeNode* root) {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
        }
        
        int next() {
            TreeNode* temp=st.top();
            int val=temp->val;
            st.pop();
    
            TreeNode* temp2=temp->right;
            while(temp2!=NULL)
            {
                st.push(temp2);
                temp2=temp2->left;
            }
            return val;
        }
        
        bool hasNext() {
            return !st.empty();
        }
    };
    
    /**
     * Your BSTIterator object will be instantiated and called as such:
     * BSTIterator* obj = new BSTIterator(root);
     * int param_1 = obj->next();
     * bool param_2 = obj->hasNext();
     */