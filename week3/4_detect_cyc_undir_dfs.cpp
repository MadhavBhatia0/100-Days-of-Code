bool detect(vector<int> adj[],int vis[],int node,int parent)
  {
      if(!vis[node])
      {
          vis[node]=1;
      
      for(auto adjn : adj[node])
      {
          if(adjn!=parent)
          {
              if(detect(adj,vis,adjn,node))
              return true;
          }
      }
      }
      else{
          return true;
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(adj,vis,i,-1))
                return true;
            }
        }
        return false;
    }
// SC recursion stack + vis + =N+N
// TC O(N+2E)+O(N) traversing each node and each edge twice(degree of graph)+ main wala for loop(in worst case it will run for n times(disconnected graph))