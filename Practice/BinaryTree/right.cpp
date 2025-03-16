//199. Binary Tree Right Side View
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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> a;
            if(!root) return a;
    
            map<int,int> mpp;
            queue<pair<TreeNode*,int>> q;
            q.push({root,0});
    
            while(!q.empty())
            {
                pair<TreeNode*,int> f=q.front();
                q.pop();
                TreeNode* n=f.first;
                int level=f.second;
    
                mpp[level]=n->val;
    
                if(n->left!=NULL) q.push({n->left,level+1});
                if(n->right!=NULL) q.push({n->right,level+1});
            }
            for (auto it : mpp) {
                a.push_back(it.second);
            }       
            return a;
        }
    };
// time O(n)
//space O(n)

//using recursion
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
        vector<int> a;
        vector<int> rightSideView(TreeNode* root) {
            
            if(!root) return a;
            revpreorder(root,0);
            return a;
        }
        void revpreorder(TreeNode* root,int level)
        {
            if(!root) return;
            
            if(level==a.size())
            a.push_back(root->val);
    
            if(root->right!=NULL) revpreorder(root->right,level+1);
            revpreorder(root->left,level+1);
        }
    };

// time O(n)
//space O(n)