// Leetcode 130. Surrounded Regions
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis (m,(vector<int>(n,0)));
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O' && vis[0][i]==0)
            {
                dfs(0,i,vis,board);
            }
            if(board[m-1][i]=='O' && vis[m-1][i]==0)
            {
                dfs(m-1,i,vis,board);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
            {
                dfs(i,0,vis,board);
            }
            if(board[i][n-1]=='O' && vis[i][n-1]==0)
            {
                dfs(i,n-1,vis,board);
            }
        }
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
    int r1[4]={-1,0,1,0};
    int c1[4]={0,1,0,-1};
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& board)
    {
        int m=board.size();
        int n=board[0].size();
        if(r>=0 && c >=0 && r<m && c< n && vis[r][c]==0 && board[r][c]=='O')
        {
            vis[r][c]=1;
            for(int i=0;i<4;i++)
            {
                dfs(r+r1[i],c+c1[i],vis,board);
            }
        }
    }
};
// SC RECURSION STACK (M*N) +VIS(M*N)=O(M*N)
// TC TRAVERSING EVERY NODE =O(M*N)