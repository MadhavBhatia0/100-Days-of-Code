//GFG NUMBER OF ISLANDS
class Solution{
public:
 int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
        
    }
    int r1[8]={0,1,0,-1,1,-1,1,-1};
    int c1[8]={1,0,-1,0,1,-1,-1,1};
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        if(r<0 || c<0 || r>=n || c>=m || vis[r][c]==1 || grid[r][c]==0)
        return;
        
        vis[r][c]=1;
        for(int i=0;i<8;i++)
        {
            dfs(r+r1[i],c+c1[i],vis,grid);
        }
    }
}
// SC N*M
// TC N*M