// leetcode 547
class Solution {
    private:
    void dfs(vector<int>& vis,int node,vector<vector<int>>& isConnected)
    {
        vis[node]=1;
        for(int i=0;i<isConnected.size();i++)
        {
            int element=isConnected[node-1][i];
            if(element)
            {
                if(vis[i+1]==0)
                {
                    dfs(vis,i+1,isConnected);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n+1, 0);
        vis[0]=1;
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                count++;
                dfs(vis,i,isConnected);
            }
        }
        return count;
    }
};
// space =vis +recursion stack = o(2n)
// time =o(n) + o(V+2E) =loop + dfs