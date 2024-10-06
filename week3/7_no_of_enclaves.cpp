// Leetcode 1020. Number of Enclaves
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> vis(m,(vector<int>(n,0)));
        for(int i=0;i<n;i++)
        {
            if(grid[0][i] && !vis[0][i])
            dfs(0,i,grid,vis);
            if(grid[m-1][i] && !vis[m-1][i])
            dfs(m-1,i,grid,vis);
        }
        for(int i=0;i<m;i++)
        {
            if(grid[i][0] && !vis[i][0])
            dfs(i,0,grid,vis);
            if(grid[i][n-1] && !vis[i][n-1])
            dfs(i,n-1,grid,vis);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] && !vis[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }
    int r1[4]={-1,0,1,0};
    int c1[4]={0,1,0,-1};

    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(r>=0 && c>=0 && r<m && c<n && !vis[r][c] && grid[r][c]==1)
        {
            vis[r][c]=1;
            for(int i=0;i<4;i++)
            {
                dfs(r+r1[i],c+c1[i],grid,vis);
            }
        }
    }
};
// SC RECURSION STACK (M*N) +VIS(M*N)=O(M*N)
// TC TRAVERSING EVERY NODE =O(M*N)