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
class Solution {
public:
    TreeNode* inorder(TreeNode* root)
    {
        while(root->left!=NULL)
        root=root->left;

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val>key)
        root->left=deleteNode(root->left,key);

        if(root->val<key)
        root->right=deleteNode(root->right,key);

        if(root->val==key)
        {
            if(root->left==NULL && root->right==NULL)
            return NULL;

            if(root->left==NULL)
            return root->right;

            if(root->right==NULL)
            return root->left;

            TreeNode* successor=inorder(root->right);
            root->val=successor->val;
            root->right=deleteNode(root->right,root->val);
        }
        return root;
    }
};