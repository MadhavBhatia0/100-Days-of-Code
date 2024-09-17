public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        vector<int> ans;
        dfs(ans,vis,0,adj);
        return ans;
    }
private:
    void dfs(vector<int>& ans,int vis[], int node,vector<int> adj[])
    {
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            dfs(ans,vis,it,adj);
        }
    }
// space recursion stack,vis,dfs store o(3n)
// time  one node one rescursion and total neighbours= 2E(ineer loop)
// o(n)+o(2E)