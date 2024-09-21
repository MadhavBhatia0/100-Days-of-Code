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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> a;
        if(root==NULL)
        return a;

        queue<TreeNode*> q;
        q.push(root);
        bool l=1;

        while(!q.empty())
        {
         int size=q.size();
         vector<int> curr(size);

         for(int i=0;i<size;i++)
         {
            TreeNode* temp=q.front();
            q.pop();

            if(l)
            curr[i]=temp->val;
            else{
                curr[size-1-i]=temp->val; // we used this in reverse an array
            }

            if(temp->left !=NULL) q.push(temp->left);
            if(temp->right !=NULL) q.push(temp->right);
         }
         a.push_back(curr);
         l=(l+1)%2;
        }
        return a;
    }
};
// time O(N)
// space O(N)