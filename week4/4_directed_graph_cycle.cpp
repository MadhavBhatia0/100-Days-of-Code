// gfg Directed Graph Cycle
bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=0;i< V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj,pathvis)==true)
                return true;
            }
        }
        return false;
    }
    bool dfs(int node,int vis[],vector<int> adj[],int pathvis[])
    {
       vis[node]=1;
       pathvis[node]=1;
       for(auto it : adj[node])
       {
           if(!vis[it])
           {
               if(dfs(it,vis,adj,pathvis)==true)
                return true;
           }
           else if(pathvis[it]){
               return true;
           }
       }
       pathvis[node]=0;
       return false;
    }
// dfs with an extra path array