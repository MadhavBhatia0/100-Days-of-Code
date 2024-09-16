vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> a;
        int vis[V]={0};
        queue<int> q;
        q.push(0); // 0 indexed graph
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            a.push_back(node);
            
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return a;
    }
// gfg question
// space - o(3n) queue,bfs vector,vis array
// time- o(V)+o(2E) inner loop runs for total degree, outer for total number of nodes