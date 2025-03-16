//987. Vertical Order Traversal of a Binary Tree
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
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> a;
            if(!root) return a;
    
            queue<pair<TreeNode*,pair<int,int>>> q;
            map<int, map<int, multiset<int>>> mpp;
    
            q.push({root,{0,0}});
            while(!q.empty())
            {
                auto f=q.front();
                q.pop();
                pair<int,int> p=f.second;
                TreeNode* n=f.first;
                
                mpp[p.first][p.second].insert(n->val);
    
                if(n->left!=NULL) q.push({n->left,{p.first-1,p.second+1}});
                if(n->right!=NULL) q.push({n->right,{p.first+1,p.second+1}});
            }
            for(auto it: mpp)
            {
                vector<int> col;
                for(auto j: it.second)
                {
                    col.insert(col.end(),j.second.begin(),j.second.end());
                }
                a.push_back(col);
            }
            return a;
        }
    };
// Time Complexity: O(nlogn) due to multiset
// Space Complexity: O(n)