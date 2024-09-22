class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> a;
        if(root==NULL)
        return a;

        queue<TreeNode*> q;
        q.push(root);
        bool l=0;

        while(!q.empty())
        {
         vector<int> curr;
         int size=q.size();
         
         for(int i=0;i<q.size();i++)
         {
            TreeNode* temp=q.front();
            q.pop();
            curr.push_back(temp->val);
            if(temp->left !=NULL) q.push(temp->left);
            if(temp->right !=NULL) q.push(temp->right);
         }
         a.push_back(curr);
         
        }
        return a;
    }
};
// time O(N)
// space O(N)