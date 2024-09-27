// leetcode 994 algorithm BFS
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int countfresh=0,cnt=0;
        int tmax=0;
        queue<pair<pair<int,int>,int>> q;

        int vis[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                    if(grid[i][j]==1)
                    countfresh++;
                }
            }
        }
        
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tmax=max(t,tmax);
            q.pop();

            int nrow[4]={1,0,-1,0};
            int ncol[4]={0,-1,0,1};
// N*M *4 (4 times for every node)
            for(int i=0;i<4;i++)
            {
                int row=nrow[i]+r;
                int col=ncol[i]+c;
                if(row>=0 && row <m && col >=0 && col <n && vis[row][col]==0 && grid[row][col]==1)
                {
                    vis[row][col]=2;
                    cnt++;
                    q.push({{row,col},t+1});
                }
            }
        }
        if(cnt!=countfresh)
        return -1;
        return tmax;
    }
};
// sc= M*N;
// TC = M*N;