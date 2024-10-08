// LEETCODE 785 Is Graph Bipartite?
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        int vis[v];
        for(int i=0;i<v;i++)
        {
            vis[i]=-1;
        }
         
        for(int i=0;i<v;i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(i,0,vis,graph)==false)
                return false;
            }
        }
        return true;
    }
    bool dfs(int u,int color,int vis[],vector<vector<int>>& graph)
    {
        vis[u]=color;
        for(auto it : graph[u])
        {
            if(vis[it]!=-1)
            {
                if(color==vis[it])
                return false;
            }
            else if(dfs(it,!color,vis,graph)==false){
                return false;
            } 
        }
        return true;
    }
};
// TC V+2E
// SC V(VIS ARRAY) +V RECURSIVE STACK