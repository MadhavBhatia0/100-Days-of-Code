//lc 101
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
    bool inorder(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return 1;
        if(!left || !right) return 0;

        if(left->val!=right->val) return 0;
        return inorder(left->left,right->right) && inorder(left->right,right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root || root->left==NULL && root->right==NULL) return 1;

        return inorder(root->left,root->right);
    }
};