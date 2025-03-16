public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> a;
        if(!root) return a;
        
        queue<pair<Node*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            
            Node* n=f.first;
            int col=f.second;
            
            if(mpp.find(col)==mpp.end()) mpp[col]=n->data;
            
            if(n->left!=NULL) q.push({n->left,col-1});
            if(n->right!=NULL) q.push({n->right,col+1});
        }
        for(auto it: mpp)
        {
            a.push_back(it.second);
        }
        return a;
    }


    public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> a;
        if(!root) return a;
        
        queue<pair<Node*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            
            Node* n=f.first;
            int col=f.second;
            
            mpp[col]=n->data;
            
            if(n->left!=NULL) q.push({n->left,col-1});
            if(n->right!=NULL) q.push({n->right,col+1});
        }
        for(auto it: mpp)
        {
            a.push_back(it.second);
        }
        return a;
    
    }